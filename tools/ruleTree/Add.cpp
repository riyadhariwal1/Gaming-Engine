#include "include/Add.h"


AddRule::AddRule(string to, int value)
: to(to), value(value)
{ }

void AddRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
void AddRule::accept(AstVisitor& visitor, State& gameState , List& list, Element& element) {
    visitor.visit(*this, gameState, list, element);
}

void AddRule::execute(State& gameState) {
    Player player = gameState.getPlayers().at(0);
    player.incrementWinsBy(value);
}

void AddRule::print() {
    cout << "Add Rule:" << endl;
    cout << "    to == " << to << endl;
    cout << "    value == " << value << endl;
}