#ifndef RULE_H
#define RULE_H
#include<string>
#include<iostream>
#include<vector>
#include "GameState.h"
using namespace std;

class Rule {
    public:
        virtual void execute(GameState&){};
        virtual void print ()
        {
            cout << "BASE CLASS SHOULD NOT BE PRINTING THIS " << endl;
        }
};
#endif