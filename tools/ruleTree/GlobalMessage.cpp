#include "GlobalMessage.h"
#include "MessageParser.h"
#include <iostream>

// template Rule

GlobalMessage::GlobalMessage(string value) : value(value), decipheredMsg("")
{}

string GlobalMessage::getMessage()
{
  return value;
}

string GlobalMessage::getCompleteMessage(){
  return decipheredMsg;
}

void GlobalMessage::execute(State& gameState) {
  MessageParser msgParser(value, gameState);
  decipheredMsg = msgParser.getCompleteString();
}

void GlobalMessage::print()
{
  cout << "GlobalMessage: " << endl;
  cout << "   value == " << value << endl;
}

void GlobalMessage::accept(AstVisitor &visitor, State &gameState)
{
  visitor.visit(*this, gameState);
}
