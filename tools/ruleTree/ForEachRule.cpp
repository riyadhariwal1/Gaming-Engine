#include "include/ForEach.h"

ForEachRule::ForEachRule(string list, string element)
{
    this->list = List(list);
    this -> element = Element(element);
}

void ForEachRule::addRule(AstNode *rule)
{
    ruleList.push_back(rule);
}
void ForEachRule::execute(State &gameState)
{
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

void ForEachRule::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
