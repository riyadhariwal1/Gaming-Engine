#include "Constants.h"

Weapon::Weapon(string name, string beats)
{
    this->name = name;
    this->beats = beats;
}
void Weapon:: print()
{
    cout << "Name " << name << endl;
    cout << "Beats " << beats << endl;
}

Constants::Constants(){};
void Constants::from_json(const json &consArr)
{
    for (const auto &element : consArr)
    {
        auto name = element.at("name").get<string>();
        auto beats = element.at("beats").get<string>();
        Weapon temp(name, beats);
        weapons.push_back(temp);
    }
}
void Constants::print()
{
    for (int i = 0; i < weapons.size(); i++)
    {
        weapons[i].print();
    }
}
