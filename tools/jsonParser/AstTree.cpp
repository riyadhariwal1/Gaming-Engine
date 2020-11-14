#include "AstTree.h"


std::vector<AstNode *> AstTree::getAstTree(){
    return ruleTree;
} 
void AstTree::pushNode(AstNode* rule){
    ruleTree.push_back(rule);
}