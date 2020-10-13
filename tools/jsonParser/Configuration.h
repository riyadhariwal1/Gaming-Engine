//
// Created by dhall on 2020-10-08.
//

#ifndef SOCIAL_GAMING_CONFIGURATION_H
#define SOCIAL_GAMING_CONFIGURATION_H

#include <iostream>
using namespace std;
using json = nlohmann::json;

struct PlayerCount {
    int min;
    int max;
};

class Configuration {
private:
    string name;
    int max;
    int min;
    bool audience;
    int rounds; //have set up class instead

public:
    // Configuration(string name, int min, int max, bool audience, int rounds);
    Configuration();
    void printConfiguration();
    void from_json(const json& j) {
        j.at("name").get_to(this->name);
        j.at("player count").at("min").get_to(this->min);
        j.at("player count").at("max").get_to(this->max);
        j.at("audience").get_to(this->audience);
        j.at("setup").at("Rounds").get_to(this->rounds);
    }
    
};


#endif //SOCIAL_GAMING_CONFIGURATION_H
