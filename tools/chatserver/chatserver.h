#ifndef WEBSOCKETNETWORKING_CHATSERVER_H
#define WEBSOCKETNETWORKING_CHATSERVER_H
using networking::Message;
void onConnect(Connection c);
void onDisconnect(Connection c);
User* getUser(Connection& c);
User* getUserByName(const std::string& name);
Room* getRoomByName(const std::string& roomName);
Room* getRoomById(const int& roomId);

//chatroom command helper functions
std::string strToLower(std::string& text);
std::string extractCommand(std::string& s);
std::vector<std::string> tokenizeMessage(std::string& message);
std::deque<Message> runCommand(const Message& message);
std::vector<std::string> quoted(std::string& text);
void printMessageTokens(std::vector<std::string> tokens);
bool isCommand(const std::string& text);

//chatroom commands
std::deque<Message> command_createRoom(const Message& message);
std::deque<Message> command_joinRoom(const Message& message);
std::deque<Message> command_leaveRoom(const Message& message);
std::deque<Message> command_printRoomList(const Message& message);
std::deque<Message> command_changeName(const Message& message);
std::deque<Message> command_whisper(const Message& message);
std::deque<Message> command_showCommands(const Message& message);

//message delivery
std::deque<Message> processForRoom(const Connection& c, const std::string& text);
std::deque<Message> processForUser(const Connection& c, const std::string& text);
std::deque<Message> processMessages(const std::deque<Message> &incoming);
std::deque<Message> buildOutgoing(const std::string &log);
std::deque<Message> postOffice(const std::deque<Message>& processedMessages);
std::string getHTTPMessage(const char *htmlLocation);


