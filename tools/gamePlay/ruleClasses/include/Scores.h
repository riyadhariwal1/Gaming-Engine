#ifndef SCORES_RULE_H
#define SCORES_RULE_H
#include "Rule.h"
#include "GameState.h"
#include<string>
using namespace std;

class Scores :  public Rule {
    Scores(string, bool);
    void execute(GameState&) override;
};
#endif
