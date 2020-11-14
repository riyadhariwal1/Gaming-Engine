#include "Commands.h"
#include <sstream>

// returns a concatenated string to print to the user
std::string
Commands::listCommands() {
  std::ostringstream result;

  result << "All commands start with /\n";
  result << "/" << JOIN << " [ROOMNAME] (PIN)      Join an existing room.\n";
  result << "/" << CREATE << " [ROOMNAME] (PIN)      Create a room with an optional pin.\n";
  result << "/" << LEAVE << "      Leave current room and return to lobby.\n";
  result << "/" << ROOMLIST << "      (DEBUG) Lists all the rooms and their users.\n";
  result << "/" << WHISPER << " \"USERNAME\" \"MESSAGE\"      Send a whisper to a user. Message must be wrapped in quotes.\n";
  result << "/" << NAME << " \"NAME\"      Change your username. Wrap in quotes to include spaces.\n";
  result << "/" << COMMANDS << "      List all the commands.\n";

  return result.str();
}
