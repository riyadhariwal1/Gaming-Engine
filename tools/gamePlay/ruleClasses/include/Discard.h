#ifndef DISCARD_RULE_H
#define DISCARD_RULE_H
#include "Rule.h"
#include <string>

class DiscardRule : public Rule
{
    public:
    DiscardRule(string, string);
    void execute(State&) override;
    void print() override;
    
    private:
    string from;
    string count;
};
#endif
