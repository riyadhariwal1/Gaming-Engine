#include "Scores.h"

ScoreRule :: ScoreRule (string score, bool ascending): score(score) , ascending(ascending){}

void ScoreRule :: execute (State& gameState)
{

}
void ScoreRule:: print()
{
    cout <<"Score:" << endl;
    cout << "    score == " << score <<endl;
    cout << "    ascending == " << ascending << endl;

}
