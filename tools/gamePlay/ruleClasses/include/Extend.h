#ifndef EXTEND_RULE_H
#define EXTEND_RULE_H
#include "Rule.h"
#include <string>

class ExtendRule : public Rule
{
    public:
    ExtendRule(string, string);
    void execute(GameState&) override;
    void print () override;

    private:
    string target;
    string list;
};
#endif
