#ifndef INPUTCHOICE_RULE_H
#define INPUTCHOICE_RULE_H
#include "AstNode.h"
#include <string>

class InputChoiceRule : public AstNode
{
    public:
    InputChoiceRule(string, string, string, string);
    void execute(State&) override;
    void print() override;
    void accept(AstVisitor& visitor) override;

    private:
    string rule;
    string to;
    string prompt;
    string choices;
    string result;
    string timeout;

};
#endif
