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
  GameVariant obj = gameState.getFromState("configuration.Rounds.upfrom(1)");
  int convert = boost::get<int>(obj);
  std::cout << "it is working " << convert << std::endl;
  MessageParser msgParser(value, gameState, to_string(convert));
  decipheredMsg = msgParser.getCompleteString();
}

void GlobalMessage::execute(State& gameState, List& list, Element& element) {
  //Todo figure it out what kind of data type is needed
  //Ex: if the convert = playername this code will not work since convert is a int data type
  int convert = boost::get<int>(list.getList().at(element.getIndex()));
  MessageParser msgParser(value, gameState, to_string(convert));
  decipheredMsg = msgParser.getCompleteString();
}

void GlobalMessage::print()
{
  cout << "GlobalMessage: " << endl;
  cout << "   value == " << value << endl;
}

void GlobalMessage::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
void GlobalMessage::accept(AstVisitor& visitor, State& gameState, List& list, Element& element) {
    visitor.visit(*this, gameState, list, element);
}
