#include "include/ForEach.h"

ForEachRule::ForEachRule(string list, string element)
{
    this->list = List(list);
    this->element = Element(element);
}

void ForEachRule::addRule(Rule *rule)
{
    ruleList.push_back(rule);
}
void ForEachRule::execute(GameState &gameState)
{
}
void ForEachRule::print() 
{
    cout << "ForEach: " << endl;
    cout << "   list " ; 
    list.print();
    cout << endl;
    cout << "   element ";
    element.print();
    cout << endl;
    for (int i = 0; i < ruleList.size(); i++)
    {
        ruleList[i]->print();
    }
}