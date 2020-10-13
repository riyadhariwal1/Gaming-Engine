#ifndef SOCIAL_GAMING_VARIABLES_H
#define SOCIAL_GAMING_VARIABLES_H

#include <iostream>
#include <vector>
using namespace std;

class Variables {
private:
    vector<string>winners;    
public:
    Variables();
    void addWinner (string);
    void print();
};















#endif //SOCIAL_GAMING_VARIABLES_H
