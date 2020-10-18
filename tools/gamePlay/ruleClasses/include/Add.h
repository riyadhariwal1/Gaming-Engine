#ifndef ADD_RULE_H
#define ADD_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>

class AddRule {
    public:
    AddRule(string& variable, int count);
    void execute(GameState&) override;
};
#endif
