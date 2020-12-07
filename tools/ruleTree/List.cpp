#include "include/List.h"


List:: List(){
}
List::List (string value){
    this -> value = value;
}

void List :: execute(State& state){
    //TODO: get the list from game state
    list = state.getStateList(value);
    //TODO: Interpreter for configuration.Rounds.upfrom(1)
}

void List :: accept(AstVisitor& visitor, State& gameState)
{
    visitor.visit(*this, gameState);
}
void List::accept(AstVisitor& visitor, State& , List&, Element&) {}


vector<GameVariant> List:: getList()
{
  // how would I define a list of multiple types as an ASTNode???
    return list;
}
string List::getValue()
{
    return value;
}

void List::print() {
    cout << value;
}
