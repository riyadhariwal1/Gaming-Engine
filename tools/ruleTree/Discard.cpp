#include "include/Discard.h"

DiscardRule::DiscardRule(string from, string count)
: from(from), count(count)
{ }

void DiscardRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
void DiscardRule::execute(State &gameState) {

    vector<Player> list = gameState.getWinners();
    list.erase(list.begin(), list.begin() + std::stoi(count));
}

void DiscardRule::print()
{
  cout << "Discard rule: " << endl;
  cout << "    from == " << from << endl;
  cout << "    count == " << count << endl;
}
