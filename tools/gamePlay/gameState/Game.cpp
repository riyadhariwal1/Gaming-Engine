#include "include/Game.h"

Game::Game(AstTree astTree, State state): astTree(astTree),state(state) {}

void Game::addToMessageQueue (std::string message) {
    this->outgoing.push_back(message);
}

std::vector<std::string> Game::getOutgoing() {
    return this->outgoing;
}
//no ruleList
// Game::Game(State state, vector<AstNode*> ruleList)
//         : state(state), ruleList(ruleList)
// {}

/* vector<Weapon> Game::getConstantList(string listName) {
    if (listName == "weapons") {
        return constants.getList();
    }
    //make this a more generalized implementation (map in Constants)
    return constants.getList();
} */
