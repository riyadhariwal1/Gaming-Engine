#ifndef PARALLELFOR_RULE_H
#define PARALLELFOR_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <list>
#include <string>
#include <boost/any.hpp>
using namespace std;

class ParallelFor : public Rule
{
    public:
        ParallelFor(string, string);
        void execute(GameState&) override;
        void addRule(Rule*);
        void print() override;
    private:
        vector<Rule*> ruleList;
        string list;
        string element;
};
#endif
