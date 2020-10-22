//
// Created by Riya on 2020-10-18.
//

#ifndef SOCIAL_GAMING_GAME_H
#define SOCIAL_GAMING_GAME_H

#include <vector>
#include "Player.h"
#include "Rule.h"
#include "Constants.h"
#include "Configuration.h"
#include "Variables.h"

class Game {
private:
    vector<Player> playerList;
    Configuration configuration;
    //vector<Rule> ruleList;
    Constants constants;
    Variables variables;

public:
//    Game(vector<Player> playerList, Configuration configuration, vector<Rule> ruleList, Constants constants, Variables variables);
    Game(vector<Player> playerList, Configuration configuration, Constants constants, Variables variables);
    vector<Weapon> getConstantList(string listName);
    void print();
};


#endif //SOCIAL_GAMING_GAME_H
