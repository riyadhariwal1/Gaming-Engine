#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <any>
#include<string>
#include <unordered_map>
using namespace std;

class GameState {
    public:
        GameState::GameState(unordered_map<string,any>);
        auto getVariable(string);
        void addIntVariable(string,int);
        void addStringVariable(string,string);
    private:
        unordered_map<string,any> varMap; 
};
#endif