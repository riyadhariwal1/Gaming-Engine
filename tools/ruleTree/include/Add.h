#ifndef ADD_RULE_H
#define ADD_RULE_H
#include "AstVisitor.h"
#include "AstNode.h"
#include "Player.h"
#include <string>
using namespace std;

class AddRule : public AstNode {
public:
    AddRule(Player& variable, int count);
    void execute(State&) override;
    void print () override;
    void accept(AstVisitor& visitor, State& gameState) override;
};
#endif
