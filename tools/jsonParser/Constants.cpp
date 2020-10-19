#include "Constants.h"

Weapon::Weapon(string name, string beats){
    this->name = name;
    this->beats = beats;
}
void Constants:: addWeapon(Weapon weapon){   
    weapons.push_back(weapon);
}
void Weapon:: print(){
    cout << "   " << name << " beats " << beats << endl;
}

Constants::Constants(){};

void Constants::print(){
    cout << "Constants:" << endl;
    for (int i = 0; i < weapons.size(); i++) {
        weapons[i].print();
    }
}

vector<Weapon> Constants::getList() {
    return weapons;
}