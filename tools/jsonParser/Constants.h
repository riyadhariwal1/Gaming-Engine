#ifndef SOCIAL_GAMING_CONSTANTS_H
#define SOCIAL_GAMING_CONSTANTS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;

class Weapon{
private:
    string name;
    string beats;
    
public:
    Weapon(string name, string beats);
    void print ();
};

class Constants
{
private:
    vector<Weapon> weapons;
public:
    Constants();
    void from_json(const json &constantsArr);
    void print();
};


#endif //SOCIAL_GAMING_CONSTANTS_H