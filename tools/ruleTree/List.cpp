#include "include/List.h"


List:: List(){
}
List::List (string value){
    this -> value = value;
}

void List :: execute(State& state){
    //TODO: get the list from game state
}

void List :: accept(AstVisitor& visitor)
{
    visitor.visit(*this);
}

vector<AstNode*> List:: getList()
{
    return list;
}

void List::print() {
    cout << value;
}
