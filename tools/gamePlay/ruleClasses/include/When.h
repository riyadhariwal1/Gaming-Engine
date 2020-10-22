#ifndef WHEN_RULE_H
#define WHEN_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>
#include <vector>
using namespace std;

class Case {
    private:
        string stringCondition;
        vector<Rule*> ruleList;
    public:
        Case(string);
        Case(bool);
        void addRule(Rule* );
        void print();
};
class WhenRule :  public Rule {
    public:
        WhenRule ();
        //WhenRule(vector<Case>&);
        void execute(GameState&) override;
        void addCase(Case*);
        void print();
    private:
        vector<Case*> caseList;
        

};
#endif
