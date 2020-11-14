#include "Element.h"


Element :: Element()
{
}

Element :: Element (string value){
    this -> value = value;
}

void Element :: accept(AstVisitor& visitor)
{
    visitor.visit(*this);
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
