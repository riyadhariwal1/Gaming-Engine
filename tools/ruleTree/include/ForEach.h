#ifndef FOREACH_RULE_H
#define FOREACH_RULE_H
#include "AstNode.h"
#include "List.h"
#include "Element.h"

using namespace std;

class ForEachRule : public AstNode
{
    public:
        ForEachRule(string, string);
        void execute(GameState&) override ;
        void addRule(AstNode*);
        void print() override;
        void accept(AstVisitor& visitor) override;
    private:
        vector <AstNode*> ruleList;
        List list;
        Element element;
};
#endif
