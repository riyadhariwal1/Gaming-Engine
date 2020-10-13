#include "Variables.h"


Variables::Variables(){};

void Variables::addWinner(string str){
    winners.push_back(str);
}

void Variables::print(){
    for (int i = 0; i < winners.size(); i++) {
        cout << winners[i] << endl;
    }
}


