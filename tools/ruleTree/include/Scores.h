#ifndef SCORES_RULE_H
#define SCORES_RULE_H
#include "AstNode.h"
#include <string>
using namespace std;

class ScoreRule :  public AstNode {
public:
    ScoreRule(string, bool);
    void execute(State&) override;
    void print()override;
    void accept(AstVisitor& visitor, State& gameState) override;
    void accept(AstVisitor& visitor, State& , List&, Element&) override;

private:
    string score;
    bool ascending;
};
#endif
