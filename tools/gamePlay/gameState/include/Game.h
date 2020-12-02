//
// Created by Riya on 2020-10-18.
//

#ifndef SOCIAL_GAMING_GAME_H
#define SOCIAL_GAMING_GAME_H

#include "Player.h"
#include "Constants.h"
#include "Configuration.h"
#include "Variables.h"
#include "State.h"
#include "AstTree.h"

class Game {
private:
    AstTree astTree;
    State state;
    std::vector<std::string> outgoing;

public:
    Game (AstTree, State);
    void print();
    void execute();
    void addToMessageQueue(std::string message);
    std::vector<std::string> getOutgoing();
};


#endif //SOCIAL_GAMING_GAME_H
