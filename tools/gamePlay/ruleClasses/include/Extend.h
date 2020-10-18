#ifndef EXTEND_RULE_H
#define EXTEND_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>

class ExtendRule : public Rule
{
    public:
    ExtendRule(string, string);
    void execute(GameState&) override;
};
#endif
