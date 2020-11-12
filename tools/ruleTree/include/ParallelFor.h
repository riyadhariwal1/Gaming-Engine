#ifndef PARALLELFOR_RULE_H
#define PARALLELFOR_RULE_H
#include "AstNode.h"
#include "List.h"
#include "Element.h"
using namespace std;

class List;
class Element;

class ParallelFor : public AstNode
{
    public:
        ParallelFor(string, string);
        void execute(GameState&) override;
        void addRule(AstNode*);
        void print() override;
        void accept(AstVisitor& visitor) override;
        
    private:
        vector<AstNode*> ruleList;
        List list;
        Element element;
};
#endif
