#ifndef RULE_H
#define RULE_H
#include<string>
#include<iostream>
#include<vector>
#include "GameState.h"
#include "State.h"

using namespace std;

class Rule {
    public:
        virtual void execute(State&){};
        virtual void print ()
        {
            cout << "BASE CLASS SHOULD NOT BE PRINTING THIS " << endl;
        }
};
#endif
