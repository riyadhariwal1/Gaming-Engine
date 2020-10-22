#ifndef SCORES_RULE_H
#define SCORES_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>
using namespace std;

class ScoreRule :  public Rule {
    public:
    ScoreRule(string, bool);
    void execute(GameState&) override;
    void print()override;

    private:
    string score;
    bool ascending;
};
#endif
