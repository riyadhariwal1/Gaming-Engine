#include "include/Game.h"

Game::Game(AstTree astTree, State state): astTree(astTree),state(state)
{
    
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

void Game::execute(State& gameState) {
//    RuleAstVisitor visitor ;
//    for (auto i: astTree.getAstTree())
//    {
//        i->accept(visitor, gameState);
//    }
}
