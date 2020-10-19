//
// Created by Hoang Minh Nguyen on 12/10/2020.
//

#ifndef SOCIAL_GAMING_CONSTANTS_H
#define SOCIAL_GAMING_CONSTANTS_H

#include <iostream>
#include <vector>
using namespace std;

class Weapon{
private:
    string name;
    string beats;
    
public:
    Weapon(string name, string beats);
    void print();
};

class Constants{
private:
    vector<Weapon> weapons;

public:
    Constants();
    void addWeapon(Weapon weapon);
    void print();
    vector<Weapon> getList(); //Game class
};


#endif //SOCIAL_GAMING_CONSTANTS_H