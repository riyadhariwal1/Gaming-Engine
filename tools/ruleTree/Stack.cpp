#include "Stack.h"
#include <regex>
#include <sstream>

void TRANSLATOR::printStack(TRANSLATOR::InterpreterStack& input_stack){
  cout << "STACK:" << endl;
  while( input_stack.size() >0 ){
    cout << input_stack.top() << endl;
    input_stack.pop();
  }
  return;
}

// does not keep the first variable in stack
// like "player" or "winner"
TRANSLATOR::InterpreterStack
TRANSLATOR::Tokenizer(string& rawInput){
  TRANSLATOR::InterpreterStack newStack;

  string word="";
  auto it = rawInput.rend();
  int SKIP = 2;

  while ( it != rawInput.rbegin() ){
    word+=*it;
    cout << *it << endl;
    if(*it == ' '){
      it+=SKIP;
    } else if(*it == '='){
      newStack.push(word);
      newStack.push(OPERATOR::EQUALS);
      it+=SKIP;
    } else if(*it == '.'){
      newStack.push(word);
      newStack.push(OPERATOR::DOT);
    }
    ++it;
  }

  return newStack;
}


bool
TRANSLATOR::evaluateCondition(string& rawInput, Element& currentElement, State& state){
  InterpreterStack tokens = Tokenizer(rawInput);
  //printStack(tokens);

  bool result=true;

  // while(tokens.size()>0){
  //   result = tokens.pop();
  // }
  return result;
}
