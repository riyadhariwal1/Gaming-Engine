#ifndef STACK_H
#define STACK_H

#include <stack>
#include "State.h"
#include "Element.h"

namespace OPERATOR {
  const string DOT{"."};
  const string EQUALS{"=="};
}

namespace TRANSLATOR {

  using InterpreterStack = std::stack<string>;


  void printStack(InterpreterStack&);
  InterpreterStack Tokenizer(string&);

  bool evaluateCondition(string&, Element&, State&);

}


#endif
