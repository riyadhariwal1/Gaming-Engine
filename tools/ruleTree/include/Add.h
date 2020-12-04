#ifndef ADD_RULE_H
#define ADD_RULE_H

#include "AstNode.h"
#include "Player.h"
#include <string>
using namespace std;

class AddRule : public AstNode {
public:
    //TODO: Unsure of how to give the current player object to the add rule when going through the for each loop.
    // All we have now is a setter function which doesnt seem to be the right answer.
//    AddRule(string to, string value, Player& player);
    AddRule(string to, string value);
    void setPlayer(Player& player);

    void execute(State&) override;
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;


private:
//    Player& player;
    string to;
    string value;
};
#endif
