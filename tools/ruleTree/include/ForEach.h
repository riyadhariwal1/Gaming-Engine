#ifndef FOREACH_RULE_H
#define FOREACH_RULE_H
#include "List.h"
#include "Element.h"
#include "AstNode.h"

using namespace std;


class ForEachRule : public AstNode
{
    public:
        ForEachRule(string, string);
        void execute(State&) override ;
        void addRule(AstNode*);
        void print() override;
        void accept(AstVisitor& visitor) override;
    private:
        vector <AstNode*> ruleList;
        List list;
        Element element;
};
#endif