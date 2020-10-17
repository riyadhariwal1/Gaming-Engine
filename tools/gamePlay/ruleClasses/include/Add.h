#ifndef ADD_RULE_H
#define ADD_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>

class AddRule : public Rule
{
    public:
    AddRule(string, int);
    void execute(GameState&) override;
};
#endif
