#include "include/List.h"


List:: List(){
}
List::List (string value){
    this -> value = value;
}

void List :: execute(State& state){
    //TODO: get the list from game state
    list = state.getStateList(value);
}

void List :: accept(AstVisitor& visitor, State& gameState)
{
    visitor.visit(*this, gameState);
}

vector<GameVariant> List:: getList()
{
    return list;
}

void List::print() {
    cout << value;
}
