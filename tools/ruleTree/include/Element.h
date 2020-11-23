#ifndef ELEMENT_H
#define ELEMENT_H
#include "AstNode.h"

class Element: public AstNode{
private:
    int index;
public:
    Element();
    void execute(State&);
    void print();
    void accept(AstVisitor& visitor, State& gameState) override;
    void indexIncrement();

};

#endif
