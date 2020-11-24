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
  vector<GameVariant> list = gameState.getStateList(value);
  int convert = boost::get<int>(list.at(gameState.getCurrentRounds()-1));
  MessageParser msgParser(value, gameState, to_string(convert));
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
