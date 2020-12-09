#ifndef STACK_H
#define STACK_H

#include <stack>
#include "State.h"
#include "Element.h"

using stack_value = std::string;
using InterpreterStack = std::stack<stack_value>;


namespace OPERATOR {
  const string DOT{"."};
  const string EQUALS{"=="};
}

namespace TRANSLATOR {

  void printStack(InterpreterStack&);
  InterpreterStack Tokenizer(string&);

  bool evaluateCondition(string&, Element&, State&);

}


#endif
