#ifndef PARALLELFOR_RULE_H
#define PARALLELFOR_RULE_H
#include "AstNode.h"
#include "List.h"
#include "Element.h"
using namespace std;

class List;
class Element;

class ParallelFor : public AstNode {
public:
    ParallelFor(string, string);
    void execute(State&) override;
    void addRule(std::unique_ptr<AstNode>);
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;
    vector<std::unique_ptr<AstNode>> const& getRuleList();

private:
    std::vector<std::unique_ptr<AstNode>> ruleList;
    List list;
    Element element;
};
#endif
