#include "include/ForEach.h"

ForEachRule::ForEachRule(string list, string element) : list(list), element(element)
{
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
    cout << "   list " << list << endl;
    cout << "   element " << element << endl;
    for (int i = 0; i < ruleList.size(); i++)
    {
        ruleList[i]->print();
    }
}