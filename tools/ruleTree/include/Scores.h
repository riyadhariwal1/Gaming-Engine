#ifndef SCORES_RULE_H
#define SCORES_RULE_H
#include "AstNode.h"
#include "GameState.h"
#include <string>
using namespace std;

class ScoreRule :  public AstNode {
    public:
    ScoreRule(string, bool);
    void execute(GameState&) override;
    void print()override;
    void accept(AstVisitor& visitor) override;
    private:
    string score;
    bool ascending;
};
#endif
