#include "ParallelFor.h"

ParallelFor::ParallelFor(string list, string element)
{
    this->list = List(list);
    this -> element = Element(element);
}

void ParallelFor::addRule(std::unique_ptr<AstNode> rule){
    ruleList.push_back(std::move(rule));
}

void ParallelFor::execute(State &gameState) {
}

vector<std::unique_ptr<AstNode>> const& ParallelFor::getRuleList() {
    return ruleList;
}

void ParallelFor::print() {
    cout << "ParallelFor: " << endl;
    cout << "    list == ";
    list.print();
    cout << endl;
    cout << "    element == " ;
    element.print();
    cout << endl;
    for (int i = 0; i < ruleList.size(); i++) {
        ruleList[i]->print();
    }
}

void ParallelFor::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
void ParallelFor::accept(AstVisitor& visitor, State& , List&, Element&) {}

