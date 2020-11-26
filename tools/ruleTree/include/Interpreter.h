#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "State.h"
#include "Element.h"

namespace HELPER {
  // anything with {} is using element
  string InterpretString(string& msg, Element& element);
  string InterpretString(string& msg, State& state);
}


namespace INTERPRETER {

  vector<Player> InterpretListOfPlayers(string&, State&);

  vector<unordered_map<string,string>> InterpretList(string&, State&);

  string InterpretString(string&, Element&, State&);

  bool InterpretCondition(string&);

}
#endif
