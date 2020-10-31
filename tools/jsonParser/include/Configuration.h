//
// Created by dhall on 2020-10-08.
//

#ifndef SOCIAL_GAMING_CONFIGURATION_H
#define SOCIAL_GAMING_CONFIGURATION_H

#include <iostream>
using namespace std;

struct PlayerCount {
    int min;
    int max;
};

class Configuration {
private:
    string name;
    PlayerCount playerCount;
    bool audience;
    int rounds; //have set up class instead

public:
    Configuration(string name, int min, int max, bool audience, int rounds);
    string getName();
    PlayerCount getPlayerCount();
    bool isAudible();
    int getRounds();
    void printConfiguration();
};


#endif //SOCIAL_GAMING_CONFIGURATION_H
