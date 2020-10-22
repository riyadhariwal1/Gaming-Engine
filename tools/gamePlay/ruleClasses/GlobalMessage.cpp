#include "GlobalMessage.h"
#include <iostream>

// template Rule

GlobalMessage::GlobalMessage(string value) : value(value)
{
}

void GlobalMessage::execute(GameState& gameState)
{
  // replace in string -- need GameState varaibles first
  // Example:  "Winners: {winners.elements.name}"
  // might end up using regex ?
  size_t open = value.find("{");
  size_t close = value.find("}") - open + 1;

  string variableToReplace = value.substr(open, close);
  value.replace(open, close, "VARIABLE");
  cout << value << endl;
}

void GlobalMessage::print()
{
  cout << "GlobalMessage: " << endl;
  cout << "   value == " << value << endl;
}
