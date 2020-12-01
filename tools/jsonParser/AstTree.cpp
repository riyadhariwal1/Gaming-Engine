#include "AstTree.h"
#include "Loader.h"
AstTree::AstTree(json rules){
    for (const json element : rules)
    {
        Loader loader;
        auto rulesName = element.at("rule").get<string>();
        cout << rulesName << endl;
        if (rulesName == "foreach")
        {
            ForEachRule *ruleIndex = loader.forEachRule(element);
            this->pushNode(ruleIndex);
        }
        else if (rulesName == "scores")
        {
            ScoreRule *ruleIndex = loader.scoreRule(element);
            this->pushNode(ruleIndex);
        }
        else if (rulesName == "global-message")
        {
            GlobalMessage *ruleIndex = loader.globalMessageRule(element);
            this->pushNode(ruleIndex);
        }
    }
}
std::vector<AstNode *> AstTree::getAstTree(){
    return ruleTree;
} 
void AstTree::pushNode(AstNode* rule){
    ruleTree.push_back(rule);
}