#include "include/Add.h"

//AddRule::AddRule(string to, string value, Player& player)
//        : to(to), value(value), player(player)
//{ }

AddRule::AddRule(string to, string value)
: to(to), value(value)
{ }

void AddRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}

void AddRule::execute(State& gameState) {
    //todo: parse "to". format is "elementName.field". we have the current element, just need Field
    //todo: maybe have an editField function
    Player* player; //TODO: interpreter
    player->incrementWinsBy(std::stoi(value));
}

void AddRule::print() {
    cout << "Add Rule:" << endl;
    cout << "    to == " << to << endl;
    cout << "    value == " << value << endl;
}
