/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////
//todo: rewrite chatServer code to work with Users instead of connections
//implement room.addUser and room.removeUser.

#include "Server.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

#include "User.h"
#include "Room.h"
using networking::Server;
using networking::Connection;
using networking::Message;

// error enums
const std::string ROOM_NOT_EXIST = "ROOM_NOT_EXIST";

//list of client IDs
std::vector<User> clients;
std::vector<Room> rooms;
//ran by Server.h every time a new connection is made.
//adds a new connection (i.e client ID) to the clients vector.
void
onConnect(Connection c) {
  std::cout << "New connection found: " << c.id << "\n";
  auto newUser(c);
  clients.push_back(newUser);
}

//remove a given Id from the clients vector.
//cleans up the empty space from the vector after the Id has been removed.
void
onDisconnect(Connection c) {
  std::cout << "Connection lost: " << c.id << "\n";
  for (auto client:clients){
      if (client.getConnection() == c){
          auto eraseBegin = std::remove(std::begin(clients), std::end(clients), client);
          clients.erase(eraseBegin, std::end(clients));
      }
  }
}

//shouldShutdown is set to true, if the message's text was "Shutdown". If shouldShutdown is true, the main function's while loop will break.
struct MessageResult {
  std::string result;
  bool shouldShutdown;
};

//given a Connection, return that room;
User
getUser(Connection c){
    for (auto client:clients){
        if (client.connection == c)
            return client;
    }
    std::cout<<"Error. Trying to find user with Id "<< c.id <<"but they are not in the Client vector"<<"\n";
    throw;
}

// given a room name, return a pointer to that Room otherwise throw an error with the room not found.
Room*
getRoomByName(std::string roomName) {
  for (auto& room : rooms) {
    if (room.getRoomName() == roomName) {
      return &room;
    }
  }

  std::string error = ROOM_NOT_EXIST;
  throw error;
}

//given a specific user, find the room they're in and return a pointer to that room.
Room*
getRoom(User target){
    int counter = 0;
    for (auto room:rooms){

        auto userList = room.getUsers();
        for (auto user:userList){
            if (user == target){
                // TODO: update this function to return the correct room
                return &rooms.at(0);
            }
        }
        counter++;
    }
    std::cout<<"Error. Trying to find user with Id "<< target.connection.id <<"but they are not any room in the rooms vector"<<"\n";
    throw;
}

// Tokenize the user input to handle commands
std::vector<std::string>
tokenizeMessage(std::string message) {
  std::vector<std::string> tokens;

  std::stringstream stream(message);
  std::string temp;

  while(getline(stream, temp, ' ')) {
    tokens.push_back(temp);
  }

  return tokens;
}

// TODO: handle the /join command
void
joinChatroom(std::vector<std::string> tokens) {}

// prints the tokenized message (DEBUG ONLY)
void
printMessageTokens(std::vector<std::string> tokens) {
  std::cout << "Tokenized Message: \n";

  for (auto token : tokens)
  {
    std::cout << token << '\n';
  }
}

//called by chatserver::main();
//takes in a server (don't worry about this, theres only ever one server to consider), and a double ended queue of 'Message's (defined in Server.h)
//Reads through the dequeue of Messages.
//if the message's content was "quit", disconnect the user who sent the message.
//if the message's content was "shutdown" shutdown the server.
//else, create a new string called result that is as follows: SENDER_ID ++ ">" ++ MESSAGE_TEXT
//refer to main() to see what happens with the return value.
MessageResult
processMessages(Server& server, const std::deque<Message>& incoming) {
  std::ostringstream result;
  bool quit = false;
  for (auto& message : incoming) {
    // split the string into tokens
    std::vector<std::string> tokens = tokenizeMessage(message.text);
    printMessageTokens(tokens);

    auto commandType = tokens.at(0);

    if (message.text == "quit") {
      server.disconnect(message.c);
    } else if (message.text == "shutdown") {
        std::cout << "Shutting down.\n";
        quit = true;
    } else if (commandType == "/create") {
        // DISCUSS: the command code should be in separate functions
        std::string targetRoomName;

        try {
          targetRoomName = tokens.at(1);

          // check if the room already exists
          // if getRoomByName() does not error out, it means the room exists
          Room *room = getRoomByName(targetRoomName);
          result << "The room " << targetRoomName << " exists. Please use /join " << targetRoomName << " to join the room.\n";

        } catch (const std::exception& e) {
          // room name is not provided
          std::cout << e.what();
          result << "Please provide a room name.\n";
        } catch (const std::string& e) {
          if (e == ROOM_NOT_EXIST) {
            // TODO:
            // - create the Room with the custom name
            // - add the User to the room
            // - update the User.roomId
          }
        }
    } else if (commandType == "/join") {
        std::string targetRoomName;
        try {
          targetRoomName = tokens.at(1);

          Room* room = getRoomByName(targetRoomName);
          User user = getUser(message.c);

          user.roomId = room->getRoomId();
          room->addUser(user);

          result << "Sending User:" << message.c.id << " to room " << room->getRoomName() << ".\n";
        } catch (const std::exception& e) {
          // room name is not provided
          std::cout << e.what();
          result << "Please provide a room name.\n";
        } catch (const std::string& e) {
          // catch the custom string errors from getRoomByName()
          if (e == "ROOM_NOT_EXIST") {
            result << "Room " << targetRoomName << " does not exist. Type \"/create " << targetRoomName << "\" to make the room.\n";
          };
        }
    } else if (commandType == "/leave"){
        result << "Sending User:"<<message.c.id<<" to main room.\n";
        // rooms.at(0).addUser(getUser(message.c));
        // rooms.at(1).removeUser(getUser(message.c));
    } else if (commandType == "/roomList"){
        result << "Please check the console for debug information.\n";
        std::cout<<"\n";
        for (auto room:rooms){
            room.printUsers();
        }
    }else {
        result << message.c.id << "> " << commandType << "\n";
    }
  }
  return MessageResult{result.str(), quit};
}

//Takes in one long processed string,
//Creates a new dequeue of 'Messages' (defined in Server.h).
//Each Message is as follows: {
//                              connection =RECIPIENT_ID
//                              text = RESULT }
//note that RESULT will be the same string of text as defined in processMessages();
//The end result is one big list of 'Messages', with a recipient ID, and a line of text to send to that recipient's client.
std::deque<Message>
buildOutgoing(const std::string& log) {
  std::deque<Message> outgoing;
  for (auto client : clients) {
    outgoing.push_back({client.connection, log,0});
  }
  return outgoing;
}

//processes deque incoming messages.
//returns deque of messages in the form of
//                              Connection: Recipient ID  	(where recipient = a user who's in the same room as the sender)
//                              Text: USER_ID> MESSAGE_TEXT
//


//std::deque<Message> postOffice(const std::deque<Message>& incoming){
//    std::deque<Message> output;
//    for (auto& message : incoming) {
//        //use getRoom to find the room that contains Message->Connection
//        //for each User in that room
//            //create a new output Message for that user.
//            //add that new output Message into the output dequeue
//
//        //result << message.connection.id << "> " << message.text << "\n";
//        //return that output dequeue into server.send
//    }
//}


std::string
getHTTPMessage(const char* htmlLocation) {
  if (access(htmlLocation, R_OK ) != -1) {
    std::ifstream infile{htmlLocation};
    return std::string{std::istreambuf_iterator<char>(infile),
                       std::istreambuf_iterator<char>()};

  } else {
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
int
main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
              << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
    return 1;
  }

  unsigned short port = std::stoi(argv[1]);
  Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};

  while (true) {
    bool errorWhileUpdating = false;
    try {
      server.update();
    } catch (std::exception& e) {
      std::cerr << "Exception from Server update:\n"
                << " " << e.what() << "\n\n";
      errorWhileUpdating = true;
    }

    auto incoming = server.receive();
    auto [log, shouldQuit] = processMessages(server, incoming);
    auto outgoing = buildOutgoing(log);
    server.send(outgoing);

    if (shouldQuit || errorWhileUpdating) {
      break;
    }

    sleep(1);
  }

  return 0;
}

