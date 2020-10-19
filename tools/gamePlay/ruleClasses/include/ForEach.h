#ifndef FOREACH_RULE_H
#define FOREACH_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>
#include <boost/any.hpp>
using namespace std;

class ForEachRule : public Rule
{
    public:
        ForEachRule(string&, string&);
        void execute(GameState&) override;
        void addRule(Rule&)
    private:
        list<Rule> ruleList;
        string& listName;
        string& element;
};
#endif
