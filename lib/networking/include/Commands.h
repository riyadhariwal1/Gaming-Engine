

#ifndef WEBSOCKETNETWORKING_COMMANDS_H
#define WEBSOCKETNETWORKING_COMMANDS_H
#include <string>


struct Commands {
  std::string CREATE{"create"};
  std::string JOIN{"join"};
  std::string LEAVE{"leave"};
  std::string ROOMLIST{"roomlist"};
  std::string WHISPER{"whisper"};
  std::string COMMANDS{"commands"};
};

#endif //WEBSOCKETNETWORKING_COMMANDS_H
