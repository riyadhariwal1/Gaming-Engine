#include "Scores.h"

ScoreRule :: ScoreRule (string score, bool ascending): score(score) , ascending(ascending){}

void ScoreRule :: execute (GameState& gameState)
{

}
void ScoreRule:: print()
{   
    cout <<"Score:" << endl;
    cout << "    score == " << score <<endl;
    cout << "    ascending == " << ascending << endl;

}

void Scores::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}