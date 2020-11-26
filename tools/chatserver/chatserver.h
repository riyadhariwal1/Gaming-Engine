
#ifndef WEBSOCKETNETWORKING_CHATSERVER_H
#define WEBSOCKETNETWORKING_CHATSERVER_H
using networking::Message;
void onConnect(Connection c);
void onDisconnect(Connection c);
User* getUser(Connection c);
User* getUserByName(std::string name);
Room * getRoomByName(std::string roomName);
Room* getRoomById(int roomId);
std::string strToLower(std::string text);
std::string extractCommand(std::string s);
std::vector<std::string> tokenizeMessage(std::string message);
std::string runCommand(Message message);
std::vector<std::string> quoted(std::string text);
void printMessageTokens(std::vector<std::string> tokens);
bool isCommand(std::string text);
std::string command_createRoom(Message message);
std::string command_joinRoom(Message message);
std::string command_leaveRoom(Message message);
std::string command_printRoomList(Message message);
std::string command_changeName(Message message);
std::string command_whisper(Message message);
std::string command_startGame(Message message);
std::string command_showCommands(Message message);
std::deque<Message> processMessages(const std::deque<Message> &incoming);
std::deque<Message> buildOutgoing(const std::string &log);
std::deque<Message> postOffice(const std::deque<Message>& processedMessages);
std::string getHTTPMessage(const char *htmlLocation);

#endif //WEBSOCKETNETWORKING_CHATSERVER_H
