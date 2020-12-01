#include "include/ForEach.h"

ForEachRule::ForEachRule(string list, string element)
{
    this->list = List(list);
    this -> element = Element(element);
    this -> numLoop = 0;
}

void ForEachRule::addRule(std::unique_ptr<AstNode> rule){
    ruleList.push_back(std::move(rule));
}

void ForEachRule::execute(State &gameState)
{
    list.execute(gameState);
}
void ForEachRule::print()
{
    cout << "ForEach: " << endl;
    cout << "    list == ";
    list.print();
    cout << endl;
    cout << "    element == " ;
    element.print();
    cout << endl;
    for (int i = 0; i < ruleList.size(); i++)
    {
        ruleList[i]->print();
    }
}

void ForEachRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this,gameState);
}
void ForEachRule::accept(AstVisitor& visitor, State& , List&, Element&) {}

vector<std::unique_ptr<AstNode>> const& ForEachRule::getRuleList() {
    return ruleList;
}

int ForEachRule::getNumLoop()
{
    return numLoop;
}
void ForEachRule::setNumLoop(int num)
{
    numLoop = num;
}

List ForEachRule::getList()
{
    return list;
}
Element& ForEachRule::getElement()
{
    return element;
}
