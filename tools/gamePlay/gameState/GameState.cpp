#include "GameState.h"

GameState::GameState(unordered_map<string,boost::any> newMap): varMap(newMap){
}

auto GameState::getVariable(string name){
    return this->varMap[name];
}
void GameState::addStringVariable(string name, string value){
    this->varMap[name] =value;
}

void GameState::addIntVariable(string name, int value){
    this->varMap[name] =value;
}
