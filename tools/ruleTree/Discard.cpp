#include "include/Discard.h"

DiscardRule::DiscardRule(string from, string count) : from(from), count(count)
{
  // discard count number of elements from list
}
void DiscardRule::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
void DiscardRule::execute(State &gameState){}

void DiscardRule::print()
{
  cout << "Discard rule: " << endl;
  cout << "    from == " << from << endl;
  cout << "    count == " << count << endl;
}
