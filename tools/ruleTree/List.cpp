#include "include/List.h"


List:: List(){
}
List::List (string value){
    this -> value = value;
}

void List :: execute(State& state){
    //TODO: get the list from game state
    //testing;
    vector<int> test (2, 10);
    this ->test = test;
    //vector<GameVariant> result = state.getStateList(value);
    //TODO: Interpreter for configuration.Rounds.upfrom(1)


}

void List :: accept(AstVisitor& visitor, State& gameState)
{
    visitor.visit(*this, gameState);
}

vector<AstNode*> List:: getList()
{
    return list;
}

vector<int> List::getTest()
{
    return test;
}

void List::print() {
    cout << value;
}
