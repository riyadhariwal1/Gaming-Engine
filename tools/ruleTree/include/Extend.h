#ifndef EXTEND_RULE_H
#define EXTEND_RULE_H
#include "AstNode.h"
#include <string>

class ExtendRule : public AstNode {
public:
    ExtendRule(string, string);
    void execute(State&) override;
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;


private:
    string target;
    string list;
};
#endif
