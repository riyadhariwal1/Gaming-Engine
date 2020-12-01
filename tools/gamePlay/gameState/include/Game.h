
#ifndef SOCIAL_GAMING_GAME_H
#define SOCIAL_GAMING_GAME_H

#include "Player.h"
#include "Constants.h"
#include "Configuration.h"
#include "Variables.h"
#include "State.h"
#include "AstTree.h"
#include "RuleAstVisitor.h"

class Game {
private:
    AstTree astTree;
    State state;
public:
    Game (AstTree, State);
    void print();
    void execute(State& gameState);
};


#endif //SOCIAL_GAMING_GAME_H
