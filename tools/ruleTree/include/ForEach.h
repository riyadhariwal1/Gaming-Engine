#ifndef FOREACH_RULE_H
#define FOREACH_RULE_H
#include "List.h"
#include "Element.h"
#include "AstNode.h"

using namespace std;


class ForEachRule : public AstNode {
public:
    ForEachRule(string, string);
    void execute(State&) override ;
    void addRule(std::unique_ptr<AstNode>);
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;

    vector<std::unique_ptr<AstNode>> const& getRuleList();
    List getList();
    int getNumLoop();
    void setNumLoop(int);
    Element& getElement();
private:
    std::vector<std::unique_ptr<AstNode>> ruleList;
    List list;
    Element element;
    int numLoop;
};

#endif
