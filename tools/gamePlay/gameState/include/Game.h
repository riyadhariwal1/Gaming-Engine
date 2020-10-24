//
// Created by Riya on 2020-10-18.
//

#ifndef SOCIAL_GAMING_GAME_H
#define SOCIAL_GAMING_GAME_H

#include <vector>
#include "Rule.h"
#include "State.h"

class Game {
private:
    vector<Rule*> ruleList;
    State state;
public:
//    Game(vector<Player> playerList, Configuration configuration, vector<Rule> ruleList, Constants constants, Variables variables);
    Game(State state, vector<Rule*> ruleList);
    void print();
    void execute();
};


#endif //SOCIAL_GAMING_GAME_H
