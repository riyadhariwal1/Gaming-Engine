#include "Extend.h"

ExtendRule::ExtendRule(string list, string target): list(list), target(target) 
{
  // given a list, extend it with another list or variable
}

void ExtendRule::execute(GameState& gameState)
{

}

void ExtendRule::print()
{
  cout << "Extend Rule:" << endl;
  cout << "    list == " << list << endl;
  cout << "    target == " << target << endl;

}

