#include "When.h"

Case::Case(string condition): stringCondition(condition){}

void Case::addRule (AstNode* rule){
    ruleList.push_back(rule);
}
void Case::print() {
    cout << "Case:" << endl;
    cout << "    " << "condition == " << stringCondition << endl;
    for (int i = 0 ; i < ruleList.size(); i++) {
        ruleList[i] -> print();
    }
}

WhenRule::WhenRule(){}

//WhenRule::WhenRule(vector<Case*> &caseList)
//: caseList(caseList)
//{}


enum Outcome { Success, Failure };

Outcome isConditionTrue(Case* condition) {
    if (condition.condition){
        return Outcome::Success;
    } else {
        return Outcome::Failure;
    }
}

void WhenRule::execute(State& gameState) {
    Outcome outcome;
    for (Case condition : caseList) {
        outcome = isConditionTrue(condition);
        if (outcome == Outcome::Success) {
            executeHelper(gameState, condition);
        }
    }
}

void WhenRule::addCase (Case* condition) {
    caseList.push_back(condition);
}

void WhenRule::print() {
    for (int i = 0 ; i < caseList.size();i++) {
        caseList[i] -> print();
    }
}

void WhenRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this,gameState);
}
void WhenRule::accept(AstVisitor& visitor, State& , List&, Element&) {}
