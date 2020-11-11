#include "include/Element.h"

Element :: Element()
{
}

Element :: Element (string value){
    this -> value = value;
}



void Element :: execute(GameState& state){
    //TODO: figure out what the data is and copy it into target variable
    //from the List 
}

Rule* Element :: getTarget()
{
    return target;
}
