#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <any>
#include<string>
#include <unordered_map>
#include <boost/any.hpp>
using namespace std;


class GameState {
    public:
        GameState(unordered_map<string,boost::any>);
        //auto getVariable(string);
        void addIntVariable(string,int);
        void addStringVariable(string,string);
    private:
        unordered_map<string,boost::any> varMap;
};

#endif
