#include "include/Discard.h"

DiscardRule::DiscardRule(string from, string count) : from(from), count(count)
{
  // discard count number of elements from list
}
void DiscardRule::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
void DiscardRule::execute(State &gameState){
  vector<Player> list = gameState.getWinners();
  if(!list.empty()){
    list.erase(list.begin(), list.begin()+1);
    list.begin();
  }
}

void DiscardRule::print()
{
  cout << "Discard rule: " << endl;
  cout << "    from == " << from << endl;
  cout << "    count == " << count << endl;
}
