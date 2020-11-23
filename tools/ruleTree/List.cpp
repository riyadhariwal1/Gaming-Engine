#include "include/List.h"


List:: List(){
}
List::List (string value){
    this -> value = value;
}

void List :: execute(State& state){
    //TODO: get the list from game state
    vector<GameVariant> result = state.getStateList(value);

}

void List :: accept(AstVisitor& visitor, State& gameState)
{
    visitor.visit(*this, gameState);
}

vector<AstNode*> List:: getList()
{
    return list;
}

void List::print() {
    cout << value;
}
