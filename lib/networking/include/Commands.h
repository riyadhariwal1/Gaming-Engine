#ifndef WEBSOCKETNETWORKING_COMMANDS_H
#define WEBSOCKETNETWORKING_COMMANDS_H
#include <string>

/**
 * @class Commands
 *
 * @brief Contains all the valid user commands
 *
 * This class contains all the commands the user can use.
 * This is to avoid comparing strings in multiple places to match a command.
 **/
class Commands {
public:
  std::string CREATE{"create"};
  std::string JOIN{"join"};
  std::string LEAVE{"leave"};
  std::string ROOMLIST{"roomlist"};
  std::string WHISPER{"whisper"};
  std::string NAME{"name"};
  std::string COMMANDS{"commands"};

  std::string listCommands();
};

#endif //WEBSOCKETNETWORKING_COMMANDS_H
