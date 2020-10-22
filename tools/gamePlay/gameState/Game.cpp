#include "include/Game.h"

//Game::Game(vector<Player> playerList, Configuration configuration, vector<Rule> ruleList, Constants constants, Variables variables)
//    : playerList(playerList), configuration(configuration), ruleList(ruleList), constants(constants), variables(variables)
//{}

//no ruleList
Game::Game(vector<Player> playerList, Configuration configuration, Constants constants, Variables variables)
        : playerList(playerList), configuration(configuration), constants(constants), variables(variables)
{}

vector<Weapon> Game::getConstantList(string listName) {
    if (listName == "weapons") {
        return constants.getList();
    }
    //make this a more generalized implementation (map in Constants)
    return constants.getList();
}