#include "GlobalMessage.h"
#include "MessageParser.h"
#include <iostream>
#include "Interpreter.h"

// template Rule

GlobalMessage::GlobalMessage(string value) : value(value), decipheredMsg("")
{}

GlobalMessage::GlobalMessage(string value, Element e)
  : value(value), decipheredMsg(""), element(e) {}

Element GlobalMessage::getElement(){
  return element;
}

string GlobalMessage::getMessage(){
  return value;
}

string GlobalMessage::getCompleteMessage(){
  return decipheredMsg;
}

void GlobalMessage::execute(State& gameState) {
  // MessageParser msgParser(value, gameState);
  // decipheredMsg = msgParser.getCompleteString();

  // we need to pass element to interpreter, not the state !
}

void GlobalMessage::print()
{
  cout << "GlobalMessage: " << endl;
  cout << "   value == " << value << endl;
}

void GlobalMessage::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
