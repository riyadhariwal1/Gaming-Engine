#ifndef GLOBAL_MESSAGE_RULE_H
#define GLOBAL_MESSAGE_RULE_H

#include "AstNode.h"
#include <string>

class GlobalMessage : public AstNode {
public:
    GlobalMessage(string value);
    void execute(State&) override ;
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    string getMessage();
    string getCompleteMessage();

private:
    string value;
    string decipheredMsg;

};
#endif
