#ifndef SOCIAL_GAMING_AstTree_H
#define SOCIAL_GAMING_AStTree_H
#include "AstNode.h"
#pragma once

class AstTree {
private:
    vector<std::unique_ptr<AstNode>> ruleTree;

public:
    AstTree(const AstTree&) = delete;
    AstTree(json);
    vector<std::unique_ptr<AstNode>> const& getAstTree();
    void pushNode(std::unique_ptr<AstNode> rule);
};
#endif