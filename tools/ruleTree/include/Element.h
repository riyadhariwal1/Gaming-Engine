#ifndef ELEMENT_H
#define ELEMENT_H
#include "AstNode.h"


class Element: public AstNode{
private:
  //element is ETIHER element
    string value;
    Player player;

    AstNode* target;
    int index;

public:

    Element();
    Element(string);
    Element(Player);

    void print();
    void execute(State&);

    AstNode* getTarget();
    string getValue();
    Player getPlayer();
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;

    void indexIncrement();
    int getIndex();

};

#endif
