#ifndef SOCIAL_GAMING_VARIABLES_H
#define SOCIAL_GAMING_VARIABLES_H

#include <iostream>
#include "Parser.h"
using namespace std;

class Variables {
private:
    unordered_map<string,GameVariant> variablesMap;

public:
    Variables(unordered_map<string,GameVariant> variablesMap);
    void print();
    void addWinner (string);
};


#endif //SOCIAL_GAMING_VARIABLES_H
