#include "include/Add.h"

AddRule::AddRule(Player& player, string value)
: player(player), value(value)
{ }

void AddRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}

void AddRule::execute(State& gameState) {

}

void AddRule::print() {
    cout << "Add Rule:" << endl;
    cout << "    Player == " << &player << endl;
    cout << "    value == " << value << endl;

}
