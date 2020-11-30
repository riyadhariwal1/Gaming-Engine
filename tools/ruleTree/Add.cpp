#include "include/Add.h"

AddRule::AddRule(string to, string value, Player& player)
        : to(to), value(value), player(player)
{ }

////called in forEach loop to get current element
//AddRule::AddRule(Player& player)
//: player(player)
//{ }

void AddRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
void AddRule::accept(AstVisitor& visitor, State& , List&, Element&) {}


void AddRule::execute(State& gameState) {
    //todo: parse "to". format is "elementName.field". we have the current element, just need Field
    //todo: maybe have an editField function
    this->player.incrementWinsBy(std::stoi(value));
}

void AddRule::print() {
    cout << "Add Rule:" << endl;
    cout << "    to == " << to << endl;
    cout << "    value == " << value << endl;
}
