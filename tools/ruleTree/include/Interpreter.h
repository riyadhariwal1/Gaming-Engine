#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Stack.h"

namespace INTERPRETER {

  // re-write InterpretList to include
  vector<unordered_map<string,string>> InterpretList(string&, State&);

  string InterpretString(string&, Element&, State&);

  bool InterpretCondition(string&, Element&, State&);

}
#endif
