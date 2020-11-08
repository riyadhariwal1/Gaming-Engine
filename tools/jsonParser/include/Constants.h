//
// Created by Hoang Minh Nguyen on 12/10/2020.
//

#ifndef SOCIAL_GAMING_CONSTANTS_H
#define SOCIAL_GAMING_CONSTANTS_H

#include <boost/variant.hpp>
#include <iostream>
#include <vector>
#include "Parser.h"

using namespace std;

class Constants{
private:
    unordered_map<string,GameVariant> constantsMap;

public:
    Constants(unordered_map<string,GameVariant> constantsMap);
    void print();

};


#endif //SOCIAL_GAMING_CONSTANTS_H
