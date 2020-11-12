#ifndef WHEN_RULE_H
#define WHEN_RULE_H
#include "AstNode.h"
#include <string>
#include <vector>
using namespace std;

class Case {
    private:
        string stringCondition;
        vector<AstNode*> ruleList;
    public:
        Case(string);
        Case(bool);
        void addRule(AstNode* );
        void print();
};
class WhenRule :  public AstNode {
    public:
        WhenRule ();
        void accept(AstVisitor& visitor) override;
        //WhenRule(vector<Case>&);
        void execute(State&) override;
        void addCase(Case*);
        void print();
    private:
        vector<Case*> caseList;


};
#endif
