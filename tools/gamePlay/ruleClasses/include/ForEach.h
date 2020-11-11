#ifndef FOREACH_RULE_H
#define FOREACH_RULE_H
#include "Rule.h"
#include "List.h"
#include "Element.h"

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
        List list;
        Element element;
};
#endif
