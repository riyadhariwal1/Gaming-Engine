#ifndef ADD_RULE_H
#define ADD_RULE_H
#include "Rule.h"
#include "GameState.h"
#include "Player.h"
#include <string>
using namespace std;

class AddRule
{
public:
    AddRule(string, string);
    void execute(State&);
private:
    string to;
    string value;
};
#endif
