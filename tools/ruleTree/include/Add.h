#ifndef ADD_RULE_H
#define ADD_RULE_H

#include "AstNode.h"
#include "Player.h"
#include <string>
using namespace std;

class AddRule : public AstNode {
public:
    AddRule(string to, string value, Player& player);
    AddRule(string to, string value);
    AddRule(Player& player);
    void execute(State&) override;
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;


private:
    //just to parse, i think it would make it easier to store the current element rather
    // than the name of the element, idk though
    Player& player;
    string to;
    string value;
};
#endif
