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
#include <map>
#include "User.h"
#include "Room.h"
#include "chatserver.h"
#include "Store.h"
#include "Dispatch.h"
#include "runGame.h"
#include "Game.h"

using networking::Connection;
using networking::Message;
using networking::Server;

//list of client IDs
std::vector<User> clients;
std::vector<Room> rooms;

std::map<std::string, std::string (*)(Message)> commands = {
    {"join", command_joinRoom},
    {"create", command_createRoom},
    {"leave", command_leaveRoom},
    {"roomlist", command_printRoomList},
    {"name", command_changeName},
    {"whisper", command_whisper},
    {"start", command_startGame},
    {"cmds", command_showCommands}};

Store store;

//ran by Server.h every time a new connection is made.
//adds a new connection (i.e client ID) to the clients vector.
void onConnect(Connection c)
{
  std::cout << "DEV DEBUG: New connection found: " << c.id << "\n";

  User newUser(c);
  clients.push_back(newUser);
  rooms.at(0).addUser(newUser);

  // _store
  store.addUser(newUser);
  store.getLobby()->addUser(newUser);
}

//remove a given Id from the clients vector.
//cleans up the empty space from the vector after the Id has been removed.
void onDisconnect(Connection c)
{
  std::cout << "DEV DEBUG: Connection lost: " << c.id << "\n";
  for (auto client : clients)
  {
    if (client.getConnection() == c)
    {
      auto eraseBegin = std::remove(std::begin(clients), std::end(clients), client);
      clients.erase(eraseBegin, std::end(clients));
    }
  }

  // _store
  store.removeUser(c);
}

//shouldShutdown is set to true, if the message's text was "Shutdown". If shouldShutdown is true, the main function's while loop will break.
struct MessageResult
{
  std::string result;
};

//given a Connection, return that user;
// in store.h
User*
getUser(Connection c)
{
  for (auto &client : clients)
  {
    if (client.connection == c)
      return &client;
  }
  std::cout << "DEV DEBUG: Error. Trying to find user with Id " << c.id << "but they are not in the Client vector"
            << "\n";

  return nullptr;
}

// given a string of a user name, return a user
// in store.h
User*
getUserByName(std::string name){
  std::cout<<"you are whisper to "<<"\""<<name<<"\""<<"\n";
  for (auto& client : clients)
  {
    if (client.userName == name){

      return &client;
    }
  }
  std::cout << "DEV DEBUG: Error. There is no such a name among the connected users."
            << "\n";

  return nullptr;
}

// given a room name, return a pointer to that Room otherwise return nullptr
// in store.h
Room *
getRoomByName(const std::string& roomName)
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
// in store.h
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

//iterates through each character in a string, converting it into a lowercase letter.
//std::string
//strToLower(std::string& text)
//{
//    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {return std::tolower(c); });
//    return text;
//}

//extracts the first word from a command. i.e 'join' from '/join game'
std::string extractCommand(std::string s)
{
  return s.substr(1, s.find(' ') - 1);
}

// Tokenize the user input to handle commands
std::vector<std::string>
tokenizeMessage(const std::string& message)
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

std::deque<Message> command_createRoom(Message message)
{
  std::ostringstream result;
  std::string targetRoomName;
  std::string roomPin = "";
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
    auto messages = processForUser(message.c,result.str());
    output.insert(output.end(),messages.begin(),messages.end());
    return output;
  }

  // check if the room already exists
  Room *existingRoom = getRoomByName(targetRoomName);

  if (existingRoom != nullptr)
  {
    result << "The room " << targetRoomName << " exists. Please use /join " << targetRoomName
           << " to join the room.";
    auto messages = processForUser(message.c,result.str());
    output.insert(output.end(),messages.begin(),messages.end());
    return output;
  }
  else
  {
    Room newRoom(rooms.size(), targetRoomName);
    User *user = getUser(message.c);

    // check if the user provided a pin to make the room private
    // Make sure not to throw an error here
    try {
      if (tokens.size() > 2)
      {
        roomPin = tokens.at(2);
      }
    } catch (const std::out_of_range &err) {
      std::cout << err.what() << "\n";
    }

    // apply pin to room
    if (!roomPin.empty())
    {
        std::cout << "DEV DEBUG: Room name is not provided for /create" << '\n';
        std::cout << e.what() << "\n";
        std::ostringstream text;
        text << "Please include a room name.";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
        return output;
    }

    // leave the user's current room
    Room *currentRoom = getRoomById(user->getRoom());

    if (currentRoom != nullptr)
    {
        std::ostringstream text;
        text << "The room " << targetRoomName << "already exists. Please use /join " << targetRoomName << " to join the room.";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
        return output;
    }

        // leave the user's current room
        Room* currentRoom = getRoomById(user->getRoom());

        if (currentRoom != nullptr) {
            currentRoom->removeUser(*user);
        }

        newRoom.addUser(*user);
        rooms.push_back(newRoom);
        std::ostringstream text;
        text << "Created and joined room " << targetRoomName << " (" << newRoom.getRoomId() << ").";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
    }
    return output;
}
std::deque<Message> command_joinRoom(const Message& message){
  std::deque<Message> output;
  std::string targetRoomName;
  std::vector<std::string> tokens;

  std::ostringstream result;


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

    User *user = getUser(message.c);
    Room *existingRoom = getRoomByName(targetRoomName);

    // We check the target room exists before kicking the user out of their room
    if (existingRoom == nullptr)
    {
      result << "Room " << targetRoomName << " does not exist. Type \"/create " << targetRoomName << "\" to make the room.\n";
      auto messages = processForUser(message.c,result.str());
      output.insert(output.end(),messages.begin(),messages.end());
      return output;
    }

    std::string pin;
    // check if the room is private and user provided a pin
    if (existingRoom->isPrivate())
    {
        std::cout << e.what() << "\n";
        std::ostringstream text;
        text << "Please include a room name.";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
        return output;
    }


    targetRoomName = tokens.at(1);
    User* user = getUser(message.c);
    Room* existingRoom = getRoomByName(targetRoomName);

    // We check the target room exists before kicking the user out of their room
    if (existingRoom == nullptr)
    {
        std::ostringstream text;
        text << "Room " << targetRoomName << " does not exist. Type \"/create " << targetRoomName << "\" to make the room.";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
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
        std::ostringstream text;
        text << "Sending you to room: " << existingRoom->getRoomName();
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
    }
    return output;
}
std::deque<Message> command_leaveRoom(const Message& message){
    std::deque<Message> output;
    User* user = getUser(message.c);

    if (user->roomId == 0) {
        std::ostringstream text;
        text << "You are already in the Main Lobby.";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
    } else {
        Room *room = getRoomById(user->getRoom()); // this shouldn't fail...

        room->removeUser(*user);
        rooms.at(0).addUser(*user);
        std::ostringstream text;
        text << "Sending User:" << user->getConnection().id << " to main lobby.";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
    }
    return output;
}

std::string command_startGame(Message message)
{
  std::ostringstream result;
  User *user = getUser(message.c);
  Room* room = getRoomById(message.sendersRoomId);

  Game& game = createGame();
  room->setGame(&game);

  result << "Game started for room " << room->getRoomId() << "\n";

  return result.str();
}

// print the available rooms to the user
// also print detailed room into the console
// todo: show lock icon next to private rooms
std::deque<Message> command_printRoomList(const Message& message){
    std::deque<Message> output;
    std::ostringstream result;
    result << "Here are the available rooms.\n";
    std::cout << "\n";
    User* user = getUser(message.c);
    for (auto room : rooms)
    {
        result<< room.getRoomName() << (user->getRoom() == room.getRoomId() ? " (current)" : "") << "\n";
        room.printUsers();
    }

    auto messages = processForUser(message.c,result.str());
    output.insert(output.end(),messages.begin(),messages.end());
    return output;
}
std::deque<Message> command_changeName(const Message& message){
    std::deque<Message> output;
    std::string targetName;
    std::ostringstream text;
    auto tokens = tokenizeMessage(message.text);
    if (tokens.size() == 1){
        std::cout<<"Fuck"<<"\n";
        text << "Please include a name to change to.";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
        return output;
    }
    if (tokens.size() > 3){
        std::cout<<"Me"<<"\n";
        text << "Sorry, you are not allowed to have a name consisting of multiple words..";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
        return output;
    }

    targetName = tokens.at(1);
    if (std::all_of(targetName.begin(),targetName.end(),isspace))
    {
        std::cout<<"Harder"<<"\n";
        text << "Please include a name to change to.";
        auto messages = processForUser(message.c,text.str());
        output.insert(output.end(),messages.begin(),messages.end());
        return output;
    }
    auto oldName = getUser(message.c)->getUserName();
    User* user = getUser(message.c);
    user->setUserName(targetName);

    text << "You have changed your name from: " << oldName << " to " << targetName;
    auto messages = processForUser(message.c,text.str());
    output.insert(output.end(),messages.begin(),messages.end());

    std::cout << "DEV DEBUG: User " << user->connection.id << " changed their name from " <<oldName <<" to " << targetName << std::endl;
    return output;
}

std::deque<Message> command_whisper(const Message& message){
    std::deque<Message> output;

    try{
        auto tokens = tokenizeMessage(message.text);
        if (tokens.size() == 1){
            auto messages = processForUser(message.c,"Please include a recipient.");
            output.insert(output.end(),messages.begin(),messages.end());
            return output;
        }
        if (tokens.size() == 2){
            std::ostringstream text;
            text << "Please include a message to send to:"  <<tokens.at(1);
            auto messages = processForUser(message.c,text.str());
            output.insert(output.end(),messages.begin(),messages.end());
            return output;
        }

        auto recipient = getUserByName(tokens.at(1));
        if (recipient == nullptr){
            std::ostringstream text;
            text << "No user found with the name of: "  << tokens.at(1);
            auto messages = processForUser(message.c,text.str());
            output.insert(output.end(),messages.begin(),messages.end());
            return output;
        } else{
            std::ostringstream text;
            text << "(Whisper) 	\t" << getUser(message.c)->getUserName() << ">";

            for (size_t i=2;i<tokens.size();i++){
                text << " ";
                text << tokens.at(i);
            }
            auto messages = processForUser(message.c,text.str());
            output.insert(output.end(),messages.begin(),messages.end());
            messages = processForUser(recipient->getConnection(),text.str());
            output.insert(output.end(),messages.begin(),messages.end());
            return output;
        }

    }
    catch (const std::exception &e){
        auto messages = processForUser(message.c,"Please include a recipient.");
        output.insert(output.end(),messages.begin(),messages.end());
        return output;
    }

}
std::deque<Message> command_showCommands(const Message& message){
    std::deque<Message> output;
    std::ostringstream result;
    result <<"List of Commands:"<<"\n";
    for(auto pair:commands){
        result<<pair.first<<"\n";
    }

    auto messages = processForUser(message.c,result.str());
    output.insert(output.end(),messages.begin(),messages.end());
    return output;
}

const char commandPrefix = '/';

std::deque<Message>
runCommand(const Message& message)
{
    std::deque<Message> output;
    std::ostringstream result;
    std::string commandName = extractCommand(message.text);
    std::transform(commandName.begin(), commandName.end(), commandName.begin(), [](unsigned char c) {return std::tolower(c); });



    std::cout << "DEV DEBUG: Attempting to call command:" << commandName << "\n";
    auto search = commands.find(commandName);
    if (search != commands.end()) {
      return search->second(message);
    } else {
         std::cout << "DEV DEBUG: Tried to run command: " << commandPrefix << commandName << " but it was not an actual command"
              << "\n";
        std::ostringstream text;
        text << "Error: " << commandName << " is not a valid command. Please type /cmds for a list of commands.";
         return processForUser(message.c,text.str());
    }

}

// extract content by way of quotation marks
std::vector<std::string>
quoted(std::string& text){
  std::vector<std::string> v;
  std::istringstream newText(text);
  std::string s;

  while (newText >> std::quoted(s))
  {
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

bool isCommand(const std::string& text)
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
        auto messages = runCommand(message);
        outgoing.insert(outgoing.begin(),messages.begin(),messages.end());
    }
    else
    {
        std::ostringstream text;
        text << user->getUserName() << "> " << message.text;
        auto messages = processForRoom(message.c,text.str());
        outgoing.insert(outgoing.begin(),messages.begin(),messages.end());
    }

  }
  return outgoing;
}
//given a userId and a string of text, create a deque of outgoing Messages for every user in the same room of that userId.
std::deque<Message>
processForRoom(const Connection& c, const std::string& text){
    Room* room = getRoomById(getUser(c)->getRoom());
    std::deque<Message> output;
    for (auto user : room->getUsers()) {
        output.push_back({user.connection, text});
    }
    return output;
}

//given a userID and a string of text, create a deque  outgoing Messages containing just a message for the receiving user.
std::deque<Message>
processForUser(const Connection& c, const std::string& text){
    std::deque<Message> output;
    output.push_back({c, text});
    return output;
}

// takes the the messages from processMessages()
// and creates a deque of output Messages assigned to the appropriate room members
// returns deque of messages in the form of
//                              Connection: Recipient ID  	(where recipient = a user who's in the same room as the sender)
//                              Text: USER_ID> MESSAGE_TEXT
//std::deque<Message>
//postOffice(const std::deque<Message>& processedMessages){
//   std::deque<Message> output;
//   for (auto& message : processedMessages) {
//        auto sendersRoom = getRoomById(message.sendersRoomId);
//
//        // check if message.whisperId exists
//        // if true, push_back one message object to the whisperId
//        // else, send message to all rooms members as normal
//
//        if (message.whisperID.id != 0){
//          output.push_back({ message.c, message.text});
//          output.push_back({ message.whisperID, message.text, message.sendersRoomId});
//        }
//        else{
//          for (auto user : sendersRoom->getUsers()) {
//            output.push_back({ user.connection, message.text, message.sendersRoomId});
//          }
//        }
//   }
//
//   return output;
//}

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

//todo: Given a deque of messages, attach more messages to it. Send the text in 'MessageText' to everyone in 'room'
//std::deque<Message>
//messageToRoom(std::string MessageText, std::deque<Message> messages, Room room){
//
//}


//runs indefinitely, until it receives a message where 'shouldQuit' is true. (refer to processMessages() to see when 'quit' is set to true')

//for every instance of the while loop:
//      Get a list of Message objects from the server.      (The Message contains the Id of the user who sent it, and the string of text of the message.)
//      Processes each message                              (Converts each message to the form of "USER_ID > MESSAGE_TEXT")
//      Builds a list of outgoing Message Objects           (Creates a new list of Message Objects, that contain the ID of the recipient, and text, converted as above.)
//      Sends the list of Message Objects back to the server.
int main(int argc, char *argv[])
{
    std::cout<<"Please go to: http://localhost:"<<argv[1]<<"/index.html"<<"\n";
  if (argc < 3)
  {
    std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
              << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
    return 1;
  }

  unsigned short port = std::stoi(argv[1]);
  Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};
  Dispatch dispatch{server, store}; // ignore

  // create the main lobby
  // _store handles this internally
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
    auto outgoing = processMessages(incoming);
    // auto outgoing = buildOutgoing(log);
//    auto outgoing = postOffice(messages);


    server.send(outgoing);

    if (errorWhileUpdating)
    {
      break;
    }

    sleep(1);
  }

  return 0;
}
