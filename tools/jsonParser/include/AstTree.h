#ifndef SOCIAL_GAMING_AstTree_H
#define SOCIAL_GAMING_AStTree_H
#include "AstNode.h"

class AstTree
{
private:
    std::vector<AstNode *> ruleTree;

public:
    std::vector<AstNode *> getAstTree();
    void pushNode(AstNode *);
};
#endif