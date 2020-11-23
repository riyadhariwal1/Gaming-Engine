#include "Element.h"


Element :: Element()
{
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



void Element::print() {
    cout << index;
}
void Element::indexIncrement()
{
    index++;
}
