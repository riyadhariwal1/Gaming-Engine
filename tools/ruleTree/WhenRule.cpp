#include "include/When.h"

Case :: Case(string condition): stringCondition(condition){}

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

void WhenRule::execute(State& gameState) {

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
