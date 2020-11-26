#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "State.h"
#include "Element.h"


namespace INTERPRETER {

  vector<Player> InterpretListOfPlayers(string&, State&);

  vector<unordered_map<string,string>> InterpretList(string&, State&);

  string InterpretString(string&, Element&, State&);

  bool InterpretCondition(string&, Element&, State&);

}
#endif
