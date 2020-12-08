#include "Stack.h"
#include <regex>
#include <sstream>

void TRANSLATOR::printStack(InterpreterStack& input_stack){
  cout << "STACK:" << endl;
  while( input_stack.size() >0 ){
    cout << input_stack.top() << endl;
    input_stack.pop();
  }
  return;
}

// does not keep the first variable in stack
// like "player" or "winner"
InterpreterStack
TRANSLATOR::Tokenizer(string& rawInput){
  InterpreterStack newStack;

  stack_value word="";
  auto it = rawInput.begin();
  int SKIP = 2;

  while ( it != rawInput.end() ){

    if(*it == ' '){
      // ignore spaces
    } else if(*it == '='){
      newStack.push(word);
      newStack.push(OPERATOR::EQUALS);
      word="";
      it+=SKIP;
    } else if(*it == '.'){
      newStack.push(word);
      newStack.push(OPERATOR::DOT);
      word="";
    } else {
      word+=*it;
    }
    ++it;
  }
  newStack.push(word);

  return newStack;
}


bool
TRANSLATOR::evaluateCondition(string& rawInput, Element& currentElement, State& state){
  InterpreterStack tokens = Tokenizer(rawInput);
  printStack(tokens);

  bool result=true;

  InterpreterStack output;
  InterpreterStack operatorStack;

  while (tokens.size() > 0)
  {
    stack_value& currentval =  tokens.top();
    tokens.pop();

    if ( currentval == OPERATOR::EQUALS)
    {
        operatorStack.push(currentval);
    } else {
        output.push(currentval);
    }
  }


  return result;
}
