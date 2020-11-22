#include "Add.h"

 AddRule::AddRule(Player& player, int count)
 : player(player), count(count)
 {}

void AddRule::execute(State& gameState) {

}

void AddRule::print() {
    cout << "Add Rule:" << endl;
    cout << "    Player == " << player << endl;
    cout << "    value == " << value << endl;

}

void AddRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}