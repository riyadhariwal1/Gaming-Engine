#include "Configuration.h"

Configuration::Configuration(string name, int min, int max, bool audience, int rounds)
    : name(name), playerCount({min, max}), audience(audience), rounds(rounds) {}


void Configuration::printConfiguration() {
    cout << "Configuration: \n"
            "   name: " << name << endl <<
         "   playerCount: min: " << playerCount.min << " max: " << playerCount.max << endl <<
         "   audience: " << audience << endl <<
         "   rounds: " << rounds << endl;
}
string Configuration::getName() {
    return name;
}
int Configuration::getRounds() {
    return rounds;
}
PlayerCount getPlayerCount() {
    return playerCount;
}
bool isAudible(){
    return audience;
}