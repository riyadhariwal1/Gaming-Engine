#include "Constants.h"

Weapon::Weapon(string name, string beats){
    this->name = name;
    this->beats = beats;
}
void Constants:: addWeapon(Weapon weapon){   
    weapons.push_back(weapon);
}
void Weapon:: print(){
    cout << "Name " << name << endl;
    cout << "Beats " << beats << endl;
}

Constants::Constants(){};

void Constants::print(){
    for (int i = 0; i < weapons.size(); i++)
    {
        weapons[i].print();
    }
}
