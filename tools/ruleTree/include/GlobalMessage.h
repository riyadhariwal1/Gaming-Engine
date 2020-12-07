#ifndef GLOBAL_MESSAGE_RULE_H
#define GLOBAL_MESSAGE_RULE_H

#include "AstNode.h"
#include "List.h"
#include "Element.h"
#include <string>

class GlobalMessage : public AstNode {
public:
    GlobalMessage(string value);
    GlobalMessage(string value, Element e);

    void execute(State&) override ;
    void execute(State&, List&, Element&);
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& gameState, List& list, Element& element) override;
    string getMessage();
    string getCompleteMessage();
    Element getElement();

private:
    string value;
    string decipheredMsg;
    Element element;

};
#endif
