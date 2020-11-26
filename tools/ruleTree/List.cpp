#include "include/List.h"


List:: List(){
}
List::List (string value){
    this -> value = value;
}

void List :: execute(State& state){
  
}

void List :: accept(AstVisitor& visitor, State& gameState)
{
    visitor.visit(*this, gameState);
}

vector<AstNode*> List:: getList()
{
  // how would I define a list of multiple types as an ASTNode???
    return list;
}

void List::print() {
    cout << value;
}
