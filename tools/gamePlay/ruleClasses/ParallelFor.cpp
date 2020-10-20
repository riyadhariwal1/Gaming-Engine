#include "ParallelFor.h"

ParallelFor::ParallelFor(string list, string element) : list(list), element(element)
{
}

void ParallelFor::addRule(Rule *rule)
{
    ruleList.push_back(rule);
}
void ParallelFor::execute(GameState &gameState)
{
}

void ParallelFor::print() 
{
    cout << "ParallelFor: " << endl;
    cout << "    list == " << list << endl;
    cout << "    element == " << element << endl;
    for (int i = 0; i < ruleList.size(); i++)
    {
        ruleList[i]->print();
    }
}
