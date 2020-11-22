#ifndef ADD_RULE_H
#define ADD_RULE_H
#include "AstVisitor.h"
#include "AstNode.h"
#include "Player.h"
#include <string>
using namespace std;

class AddRule {
public:
    AddRule(Player& player, int value);
    void execute(State&) override;
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;

private:
    Player& player;
    string value;
};
#endif
