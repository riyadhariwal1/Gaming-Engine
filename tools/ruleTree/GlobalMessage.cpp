#include "GlobalMessage.h"
#include <iostream>

// template Rule

GlobalMessage::GlobalMessage(string value) : value(value){}

string GlobalMessage::getMessage(){
  return value;
}

void GlobalMessage::execute(State& gameState) {

}

void GlobalMessage::print()
{
  cout << "GlobalMessage: " << endl;
  cout << "   value == " << value << endl;
}

void GlobalMessage::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
