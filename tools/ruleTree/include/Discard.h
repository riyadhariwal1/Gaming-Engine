#ifndef DISCARD_RULE_H
#define DISCARD_RULE_H
#include "AstNode.h"
#include "Player.h"
#include <string>

class DiscardRule : public AstNode{
public:
    DiscardRule(string, string);
    void execute(State&) override;
    void execute(State&, List&, Element&);

    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;


private:
    string from;
    string count;
};
#endif
