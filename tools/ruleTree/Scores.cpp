#include "Scores.h"
#include <bits/stdc++.h>
ScoreRule::ScoreRule (string score, bool ascending)
        : score(score) , ascending(ascending)
{ }

void ScoreRule::execute (State& gameState) {
    //TODO: the score should determine what field we should sort by
    vector<Player> list = gameState.getPlayers();
    if (this->ascending) {
        sort(gameState.getWinners().begin(), gameState.getWinners().end(), [] (Player& player1, Player& player2) {
            return (player1.getGameWins() < player2.getGameWins());
        });
    }
}

void ScoreRule:: print() {
    cout <<"Score:" << endl;
    cout << "    score == " << score <<endl;
    cout << "    ascending == " << ascending << endl;

}

void ScoreRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this,gameState);
}
void ScoreRule::accept(AstVisitor& visitor, State& , List&, Element&) {}

