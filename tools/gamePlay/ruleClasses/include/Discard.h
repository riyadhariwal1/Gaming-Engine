#ifndef DISCARD_RULE_H
#define DISCARD_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>

class DiscardRule : public Rule {
public:
    DiscardRule(string, int);
    void execute(GameState&) override;

private:

};
#endif
