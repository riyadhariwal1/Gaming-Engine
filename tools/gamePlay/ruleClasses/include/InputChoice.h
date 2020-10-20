#ifndef INPUTCHOICE_RULE_H
#define INPUTCHOICE_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>

class InputChoiceRule : public Rule
{
    public:
    InputChoiceRule(string, string, string, string);
    void execute(GameState&) override;
    void print() override;

    private:
    string rule;
    string to;
    string prompt;
    string choices;
    string result;
    string timeout;
    
};
#endif
