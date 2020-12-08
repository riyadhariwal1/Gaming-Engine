#ifndef ADD_RULE_H
#define ADD_RULE_H

#include "AstNode.h"
#include "Player.h"
#include <string>
using namespace std;

class AddRule : public AstNode {
public:
    AddRule(string to, int value);
    void execute(State&) override;
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;

private:
    string to;
    int value;
};
#endif
