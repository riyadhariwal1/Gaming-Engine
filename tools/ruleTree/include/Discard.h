#ifndef DISCARD_RULE_H
#define DISCARD_RULE_H
#include "AstNode.h"
#include <string>

class DiscardRule : public AstNode{
    public:
    DiscardRule(string, string);
    void execute(GameState&) override;
    void print() override;
    void accept(AstVisitor& visitor) override;
    
    private:
    string from;
    string count;
};
#endif
