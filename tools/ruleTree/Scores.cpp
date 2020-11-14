#include "Scores.h"
#include <bits/stdc++.h>
ScoreRule::ScoreRule (string score, bool ascending)
: score(score) , ascending(ascending)
{ }

void ScoreRule::execute (State& gameState) {
    vector<Player> list = gameState.getWinners();
    if (ascending) {
//        sort(gameState.getWinners().begin(), gameState.getWinners().end());
    }
}

void ScoreRule:: print() {
    cout <<"Score:" << endl;
    cout << "    score == " << score <<endl;
    cout << "    ascending == " << ascending << endl;

}

void ScoreRule::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
