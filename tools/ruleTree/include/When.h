#ifndef WHEN_RULE_H
#define WHEN_RULE_H
#include "AstNode.h"
#include <string>
#include <vector>
using namespace std;

class Case {
private:
    string stringCondition;
    std::vector<std::unique_ptr<AstNode>> ruleList;
public:
    Case(string);
    Case(const Case&) = delete;
    void addRule(std::unique_ptr<AstNode>);
    void print();
};

class WhenRule :  public AstNode {
    public:
        WhenRule();
        WhenRule(const WhenRule&) = delete;
        void accept(AstVisitor& visitor, State& gameState) override;
        void accept(AstVisitor& visitor, State& , List&, Element&) override;

        void execute(State&) override;
        void execute(State&, List&, Element&);
        void addCase(std::shared_ptr<Case>);
        void print();
    private:
        std::vector< std::shared_ptr<Case> > caseList;

};

#endif
