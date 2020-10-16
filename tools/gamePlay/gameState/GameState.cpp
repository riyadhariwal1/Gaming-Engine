#include "GameState.h"

GameState::GameState(map<string,any> newMap): varMap(newMap){
}

auto GameState::getVariable(string name){
    return any_cast<auto>
}
void GameState::addStringVariable(string name, string value){
    this->varMap[name] =value;
} 

void GameState::addIntVariable(string name, int value){
    this->varMap[name] =value;
} 