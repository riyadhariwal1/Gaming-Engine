/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Server.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <iomanip>

#include "User.h"
#include "Room.h"
using networking::Connection;
using networking::Message;
using networking::Server;

//list of client IDs
std::vector<User> clients;
std::vector<Room> rooms;
//ran by Server.h every time a new connection is made.
//adds a new connection (i.e client ID) to the clients vector.
void onConnect(Connection c)
{
  std::cout << "New connection found: " << c.id << "\n";

  User newUser(c);
  clients.push_back(newUser);
  rooms.at(0).addUser(newUser);
}

//remove a given Id from the clients vector.
//cleans up the empty space from the vector after the Id has been removed.
void onDisconnect(Connection c)
{
  std::cout << "Connection lost: " << c.id << "\n";
  for (auto client : clients)
  {
    if (client.getConnection() == c)
    {
      auto eraseBegin = std::remove(std::begin(clients), std::end(clients), client);
      clients.erase(eraseBegin, std::end(clients));
    }
  }
}

//shouldShutdown is set to true, if the message's text was "Shutdown". If shouldShutdown is true, the main function's while loop will break.
struct MessageResult
{
  std::string result;
};

//given a Connection, return that user;
User*
getUser(Connection c)
{
  for (auto& client : clients)
  {
    if (client.connection == c)
      return &client;
  }
  std::cout << "Error. Trying to find user with Id " << c.id << "but they are not in the Client vector"
            << "\n";

  return nullptr;
}

// given a string of a user name, return a user
User*
getUserByName(std::string name){
  for (auto& client : clients)
  {
    if (client.userName == name)
      return &client;
  }
  std::cout << "Error. There is no such a name among the connected users."
            << "\n";

  return nullptr;
}

// given a room name, return a pointer to that Room otherwise return nullptr
Room *
getRoomByName(std::string roomName)
{
  for (auto &room : rooms)
  {
    if (room.getRoomName() == roomName)
    {
      return &room;
    }
  }

  return nullptr;
}

// given a room id, return a pointer to that Room otherwise return nullptr
Room*
getRoomById(int roomId)
{
  for (auto &room : rooms)
  {
    if (room.getRoomId() == roomId)
    {
      return &room;
    }
  }

  return nullptr;
}

//iterates through each character in a string, converting it into a lowercase letter if necessary.
std::string
strToLower(std::string text)
{
  int counter = 0;
  for (auto character : text)
  {
    text[counter] = tolower(character);
    counter++;
  }
  return text;
}

//extracts the first word from a command. i.e 'join' from '/join game'
std::string extractCommand(std::string s)
{
  return s.substr(1, s.find(' ') - 1);
}

// Tokenize the user input to handle commands
std::vector<std::string>
tokenizeMessage(std::string message)
{
  std::vector<std::string> tokens;

  std::stringstream stream(message);
  std::string temp;

  while (getline(stream, temp, ' '))
  {
    tokens.push_back(temp);
  }

  return tokens;
}

const char commandPrefix = '/';

std::string
runCommand(Message message)
{
  std::ostringstream result;
  std::string commandName = strToLower(extractCommand(message.text));
  std::cout << "Attempting to call command:" << commandName << "\n";

  if (commandName == "join")
  {
    std::string targetRoomName;
    std::vector<std::string> tokens;

    try
    {
      tokens = tokenizeMessage(message.text);
    }
    catch (const std::exception &e)
    {
      std::cout << e.what() << "\n";
    }

    try
    {
      targetRoomName = tokens.at(1);

      User* user = getUser(message.c);
      Room* existingRoom = getRoomByName(targetRoomName);

      // We check the target room exists before kicking the user out of their room
      if (existingRoom == nullptr)
      {
        result << "Room " << targetRoomName << " does not exist. Type \"/create " << targetRoomName << "\" to make the room.\n";
      }
      else
      {
        Room *currentRoom = getRoomById(user->getRoom());

        if (currentRoom != nullptr)
        {
          // remove the user from their current room
          currentRoom->removeUser(*user);
        }

        existingRoom->addUser(*user);
        result << "Sending User:" << message.c.id << " to room " << existingRoom->getRoomName() << ".\n";
      }
    }
    catch (const std::exception &e)
    {
      // room name is not provided
      std::cout << "No room provided for /join"
                << "\n";
      std::cout << e.what() << "\n";
      result << "Please provide a room name.\n";
    }
  }
  else if (commandName == "leave")
  {
    User* user = getUser(message.c);

    if (user->roomId == 0) {
      result << "You are already in the Main Lobby.\n";
    } else {
      Room *room = getRoomById(user->getRoom()); // this shouldn't fail...

      room->removeUser(*user);
      rooms.at(0).addUser(*user);
      result << "Sending User:" << user->getConnection().id << " to main lobby.\n";
    }
  }
  else if (commandName == "roomlist")
  {
    // print the available rooms to the user
    // also print detailed room into the console
    // todo: show lock icon next to private rooms
    result << "Here are the available rooms.\n";
    result << "(Please check the console for debug information.)\n";
    result << "\n";
    std::cout << "\n";

    User* user = getUser(message.c);

    for (auto room : rooms)
    {
      result << room.getRoomName() << (user->getRoom() == room.getRoomId() ? " (current)" : "") << "\n";
      room.printUsers();
    }
  }
  else if (commandName == "create")
  {
    std::string targetRoomName;
    auto tokens = tokenizeMessage(message.text);

    try
    {
      targetRoomName = tokens.at(1);
    }
    catch (const std::exception &e)
    {
      std::cout << "Room name is not provided for /create" << '\n';
      std::cout << e.what() << "\n";
      result << "Please provide a room name.\n";
    }

    // check if the room already exists
    Room *existingRoom = getRoomByName(targetRoomName);

    if (existingRoom != nullptr)
    {
      result << "The room " << targetRoomName << " exists. Please use /join " << targetRoomName
             << " to join the room.\n";
    }
    else
    {
      Room newRoom(rooms.size(), targetRoomName);
      User* user = getUser(message.c);

      // leave the user's current room
      Room* currentRoom = getRoomById(user->getRoom());
      std::cout << currentRoom->getRoomId() << "\n";

      if (currentRoom != nullptr) {
        currentRoom->removeUser(*user);
      }

      newRoom.addUser(*user);
      rooms.push_back(newRoom);
      result << "Created and joined room " << targetRoomName << " (" << newRoom.getRoomId() << ").\n";
    }
  }
  else if (commandName == "name"){
    std::string targetName;
    auto tokens = tokenizeMessage(message.text);
    
    for (size_t i=1;i<tokens.size();i++){
      targetName += tokens.at(i);
      targetName += " ";
    }

    User* user = getUser(message.c);
    user->setUserName(targetName);
    std::cout << "You changed your name to " << targetName << std::endl;
  }
  else if (commandName == "whisper"){
  }
  else
  {
    std::cout << "Tried to run command: " << commandPrefix << commandName << " but it was not an actual command"
              << "\n";
  }
  return result.str();
}

// extract content by way of quotation marks
std::vector<std::string>
quoted(std::string text){
  std::vector<std::string> v;
  std::istringstream newText(text);
  std::string s;

  while (newText >> std::quoted(s)){
      v.push_back(s);
    }
  return v;
}

// prints the tokenized message (DEBUG ONLY)
void printMessageTokens(std::vector<std::string> tokens)
{
  std::cout << "Tokenized Message: \n";

  for (auto token : tokens)
  {
    std::cout << token << '\n';
  }
}

bool isCommand(std::string text)
{
  return text[0] == commandPrefix;
}

//called by chatserver::main();
//takes in a double ended queue of 'Message's (defined in Server.h)
//Reads through the dequeue of Messages and creates a new string called result that is as follows: SENDER_ID ++ ">" ++ MESSAGE_TEXT
//refer to main() to see what happens with the return value.
std::deque<Message>
processMessages(const std::deque<Message> &incoming)
{
  std::deque<Message> outgoing;

  for (auto &message : incoming)
  {
    std::ostringstream result;
    auto user = getUser(message.c);

    if (isCommand(message.text))
    {
      result << runCommand(message);
    }
    else if (user->getUserName() != "")
    {
      result << user->getUserName() << "> " << message.text << "\n";
    }
    else
    {
      result << message.c.id << "> " << message.text << "\n";
    }

    auto sendersRoomId = user->getRoom();
    // create a placeholder Message object
    Message tempMessage = {message.c, result.str(), sendersRoomId};

    auto v = quoted(tempMessage.text);
    if (v[0] == "/whisper"){
      User* user = getUserByName(v[1]);
      tempMessage.whisperID = user->getConnection();
    }
    // 1. extract the command and parameters again here using quoted(message.text)
    // 2. if first element == "/whisper", use the second element to find the user by name and add the Connection ID to tempMessage
    // 3, else just pass the Message forward as normal

    outgoing.push_back(tempMessage);
  }
  return outgoing;
}

//Takes in one long processed string,
//Creates a new dequeue of 'Messages' (defined in Server.h).
//Each Message is as follows: {
//                              connection =RECIPIENT_ID
//                              text = RESULT }
//note that RESULT will be the same string of text as defined in processMessages();
//The end result is one big list of 'Messages', with a recipient ID, and a line of text to send to that recipient's client.
// REPLACED WITH POSTOFFICE
std::deque<Message>
buildOutgoing(const std::string &log)
{
  std::deque<Message> outgoing;
  for (auto client : clients)
  {
    outgoing.push_back({client.connection, log, 0});
  }
  return outgoing;
}

// takes the the messages from processMessages()
// and creates a deque of output Messages assigned to the appropriate room members
// returns deque of messages in the form of
//                              Connection: Recipient ID  	(where recipient = a user who's in the same room as the sender)
//                              Text: USER_ID> MESSAGE_TEXT
std::deque<Message>
postOffice(const std::deque<Message>& processedMessages){
   std::deque<Message> output;
   for (auto& message : processedMessages) {
        auto sendersRoom = getRoomById(message.sendersRoomId);

        // check if message.whisperId exists
        // if true, push_back one message object to the whisperId
        // else, send message to all rooms members as normal

        if (message.whisperID.id != 0){
          output.push_back({ message.c, message.text, message.sendersRoomId});
          output.push_back({ message.whisperID, message.text, message.sendersRoomId});
        }
        else{
          for (auto user : sendersRoom->getUsers()) {
            output.push_back({ user.connection, message.text, message.sendersRoomId});
          }
        }
   }

   return output;
}

std::string
getHTTPMessage(const char *htmlLocation)
{
  if (access(htmlLocation, R_OK) != -1)
  {
    std::ifstream infile{htmlLocation};
    return std::string{std::istreambuf_iterator<char>(infile),
                       std::istreambuf_iterator<char>()};
  }
  else
  {
    std::cerr << "Unable to open HTML index file:\n"
              << htmlLocation << "\n";
    std::exit(-1);
  }
}

//runs indefinitely, until it receives a message where 'shouldQuit' is true. (refer to processMessages() to see when 'quit' is set to true')

//for every instance of the while loop:
//      Get a list of Message objects from the server.      (The Message contains the Id of the user who sent it, and the string of text of the message.)
//      Processes each message                              (Converts each message to the form of "USER_ID > MESSAGE_TEXT")
//      Builds a list of outgoing Message Objects           (Creates a new list of Message Objects, that contain the ID of the recipient, and text, converted as above.)
//      Sends the list of Message Objects back to the server.
int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
              << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
    return 1;
  }

  unsigned short port = std::stoi(argv[1]);
  Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};

  // create the main lobby
  Room newRoom(0, "Main");
  rooms.push_back(newRoom);

  while (true)
  {
    bool errorWhileUpdating = false;
    try
    {
      server.update();
    }
    catch (std::exception &e)
    {
      std::cerr << "Exception from Server update:\n"
                << " " << e.what() << "\n\n";
      errorWhileUpdating = true;
    }

    auto incoming = server.receive();
    auto messages = processMessages(incoming);

    // auto outgoing = buildOutgoing(log);
    auto outgoing = postOffice(messages);
    server.send(outgoing);

    if (errorWhileUpdating)
    {
      break;
    }

    sleep(1);
  }

  return 0;
}
