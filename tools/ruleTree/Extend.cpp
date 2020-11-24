#include "Extend.h"


ExtendRule::ExtendRule(string list, string target): list(list), target(target)
{}


void ExtendRule::execute(State& gameState)
{

}

void ExtendRule::print()
{
  cout << "Extend Rule:" << endl;
  cout << "    list == " << list << endl;
  cout << "    target == " << target << endl;

}


void ExtendRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
