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

class WhenRule : public AstNode {
public:
    WhenRule();
    WhenRule(std::vector<Case*> &caseList);
    void accept(AstVisitor& visitor, State& gameState) override;
    void executeHelper(State& gameState, Case* condition);
    //WhenRule(vector<Case>&);
    void execute(State&) override;
    void addCase(Case*);
    void print();

private:
    std::vector<Case*> caseList;
};

#endif
