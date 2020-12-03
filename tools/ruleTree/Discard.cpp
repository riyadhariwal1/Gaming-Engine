#include "include/Discard.h"


DiscardRule::DiscardRule(string from, string count)
: from(from), count("0")
{ }

void DiscardRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
void DiscardRule::accept(AstVisitor& visitor, State& gameState , List& list, Element& element) {
    visitor.visit(*this, gameState, list, element);
}

void DiscardRule::execute(State &gameState) {
    //Todo: this is hardcode
    // Possible solution: 1 look at the value of the "from" variable
    //                    2 get the list that corresponse with that variable
    //                    3 decipher the "count" variable 
    //                    4 update the list

    // also this code only update the vector<Player> list not the actually list inside gameState
    vector<Player> list = gameState.getWinners();
    list.erase(list.begin(), list.begin() + std::stoi(count));
}

void DiscardRule::execute(State &gameState, List& list, Element& element) {
    //Todo: This function the same as the other execute functions
}


void DiscardRule::print()
{
    cout << "Discard rule: " << endl;
    cout << "    from == " << from << endl;
    cout << "    count == " << count << endl;
}
