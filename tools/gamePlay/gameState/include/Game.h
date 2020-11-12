//
// Created by Riya on 2020-10-18.
//

#ifndef SOCIAL_GAMING_GAME_H
#define SOCIAL_GAMING_GAME_H

#include <vector>
#include "Player.h"
#include "Constants.h"
#include "Configuration.h"
#include "Variables.h"
#include "State.h"
//#include "AstNode.h"

class Game {
private:
    //vector<AstNode*> ruleList;
    State state;
public:
//    Game(vector<Player> playerList, Configuration configuration, vector<Rule> ruleList, Constants constants, Variables variables);
    //Game(State state, vector<AstNode*> ruleList);
    void print();
    void execute();
};


#endif //SOCIAL_GAMING_GAME_H
