#include "include/List.h"


List:: List(){
}
List::List (string value){
    this -> value = value;
}

void List :: execute(GameState& state){
    //TODO: get the list from game state
}


vector<Rule*> List:: getList()
{
    return list;
}