#ifndef ELEMENT_H
#define ELEMENT_H
#include "AstNode.h"

class Element: public AstNode{
private:
    string value;
    AstNode* target;
    int index;

public:
    Element();
    Element(string);
    void execute(State&);
    void print();
    void accept(AstVisitor& visitor, State& gameState) override;
    void indexIncrement();
    int getIndex();

};

#endif
