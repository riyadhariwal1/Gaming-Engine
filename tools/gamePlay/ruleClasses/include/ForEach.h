#ifndef FOREACH_RULE_H
#define FOREACH_RULE_H
#include "Rule.h"
#include "State.h"
#include <list>
#include <string>
#include <boost/any.hpp>
using namespace std;

class ForEachRule : public Rule
{
    public:
        ForEachRule(string, string);
        void execute(GameState&) override ;
        void addRule(Rule*);
        void print() override;
    private:
        vector <Rule*> ruleList;
        string list;
        string element;
};
#endif
