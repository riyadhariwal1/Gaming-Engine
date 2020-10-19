//
// Created by dhall on 2020-10-18.
//

#include "include/Game.h"

Game::Game(vector<Player> playerList, Configuration configuration, vector<Rule> ruleList, Constants constants, Variables variables)
    : playerList(playerList), configuration(configuration), ruleList(ruleList), constants(constants), variables(variables)
{}

vector<Weapon> Game::getConstants(string listName) {
    if (listName == "weapons") {
        return constants.getList();
    }
    //make this a more generalized implementation (map in Constants)
    return constants.getList();
}