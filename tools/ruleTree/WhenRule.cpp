#include "include/When.h"

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

WhenRule::WhenRule(std::vector<Case*> &caseList)
: caseList(caseList)
{}

enum Outcome { Success, Failure };

Outcome isConditionTrue(Case* condition) {
    bool conditionParsed = true; // TODO: interpreter
    if (conditionParsed){
        return Outcome::Success;
    } else {
        return Outcome::Failure;
    }
}

void WhenRule::execute(State& gameState) {
    Outcome outcome;
    for (Case* condition : caseList) {
        outcome = isConditionTrue(condition);
        if (outcome == Outcome::Success) {
            //executeHelper(gameState, condition);
            //call the rule here ?
        }
    }
}

void WhenRule::executeHelper(State& gameState, Case* condition) {

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
void WhenRule::accept(AstVisitor& visitor, State& gameState , List& list, Element& element) {
    visitor.visit(*this, gameState, list, element);
}

