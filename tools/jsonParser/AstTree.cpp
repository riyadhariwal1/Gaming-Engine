#include "AstTree.h"
#include "Loader.h"

AstTree::AstTree(json rules){
    for (const json & element : rules) {
        Loader loader;
        //cout << i++ << endl;
        auto rulesName = element.at("rule").get<string>();
        //cout << rulesName << endl;
        if (rulesName == "foreach") {
            std::unique_ptr<ForEachRule> ruleIndex = loader.forEachRule(element);
            this->pushNode(std::move(ruleIndex));
        }
        else if (rulesName == "scores") {
            std::unique_ptr<ScoreRule> ruleIndex = loader.scoreRule(element);
            this->pushNode(std::move(ruleIndex));
        }
    }
}

vector<std::unique_ptr<AstNode>> const& AstTree::getAstTree(){
    return ruleTree;
}

void AstTree::pushNode(std::unique_ptr<AstNode> rule){
    ruleTree.push_back(std::move(rule));
}