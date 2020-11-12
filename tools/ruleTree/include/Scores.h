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
    void accept(AstVisitor& visitor) override;
    private:
    string score;
    bool ascending;
};
#endif