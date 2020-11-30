#ifndef SOCIAL_GAMING_AstTree_H
#define SOCIAL_GAMING_AStTree_H
#include "AstNode.h"
#pragma once
class AstTree
{
private:
    std::vector<AstNode *> ruleTree;

public:
    AstTree(json);
    std::vector<AstNode*> getAstTree();
    void pushNode(AstNode *);
};
#endif