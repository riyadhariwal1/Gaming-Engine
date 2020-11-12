#ifndef GLOBAL_MESSAGE_RULE_H
#define GLOBAL_MESSAGE_RULE_H

#include "AstNode.h"

#include <string>

class GlobalMessage : public AstNode {
public:
    GlobalMessage(string value);
    void execute(State&) override ;
    void print() override;
    void accept(AstVisitor& visitor) override;
    string getMessage();

private:
    string value;

};
#endif
