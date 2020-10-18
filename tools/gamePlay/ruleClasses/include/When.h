#ifndef WHEN_RULE_H
#define WHEN_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>
#include <vector>
using namespace std;

struct Case {
    string condition;
    vector<Rule> ruleList;
};
class When :  public Rule {
    public:
        When(vector<Case>&);
        void execute(GameState&) override;
        void addCase(Case&);
    private:
        vector<Case> caseList;

};
#endif
