#ifndef GLOBAL_MESSAGE_RULE_H
#define GLOBAL_MESSAGE_RULE_H

#include "AstNode.h"
#include "Element.h"

#include <string>

class GlobalMessage : public AstNode {
public:
    GlobalMessage(string value);
    GlobalMessage(string value, Element e);

    void execute(State&) override ;
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    string getMessage();
    string getCompleteMessage();
    Element getElement();

private:
    string value;
    string decipheredMsg;
    Element element;

};
#endif
