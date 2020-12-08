#include "include/When.h"

Case::Case(string condition): stringCondition(condition){}

void Case::addRule (std::unique_ptr<AstNode> rule){
    ruleList.push_back(std::move(rule));
}

void Case::print() {
    cout << "Case:" << endl;
    cout << "    " << "condition == " << stringCondition << endl;
    for (int i = 0 ; i < ruleList.size(); i++) {
        ruleList[i] -> print();
    }
}

WhenRule::WhenRule(){}

enum Outcome { Success, Failure };

Outcome isConditionTrue(std::shared_ptr<Case> condition) {
    bool conditionParsed = true; // TODO: interpreter
    if (conditionParsed){
        return Outcome::Success;
    } else {
        return Outcome::Failure;
    }
}

void WhenRule::execute(State& gameState) {
    Outcome outcome;
    for (auto condition : caseList) {
        outcome = isConditionTrue(condition);
        if (outcome == Outcome::Success) {

        }
    }
}

void WhenRule::addCase (std::shared_ptr<Case> condition) {
    caseList.push_back(std::move(condition));
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

