#include "Element.h"


Element :: Element()
{
    index = 0;
}

Element :: Element (string value){
    this -> value = value;
    index = 0;
}

void Element :: accept(AstVisitor& visitor, State& gameState)
{
    visitor.visit(*this,gameState);
}

void Element :: execute(State& state){
    //TODO: figure out what the data is and copy it into target variable
    //from the List
}

AstNode* Element :: getTarget()
{
    return target;
}

void Element::print() {
    cout << value;
}
