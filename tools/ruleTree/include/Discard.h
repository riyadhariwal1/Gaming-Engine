#ifndef DISCARD_RULE_H
#define DISCARD_RULE_H
#include "AstNode.h"
#include "Player.h"
#include <string>

class DiscardRule : public AstNode{
    public:
    DiscardRule(string, string);
    void execute(State&) override;
    void print() override;
    void accept(AstVisitor& visitor) override;

    private:
    string from;
    string count;
};
#endif
