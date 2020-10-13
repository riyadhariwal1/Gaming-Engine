
#include "Configuration.h"

// Configuration::Configuration(string name, int min, int max, bool audience, int rounds)
//         : name(name), playerCount({min, max}), audience(audience), rounds(rounds) {}

// Configuration::Configuration(string name, int min, int max, bool audience, int rounds)
//         : name(name), min(min),max (max), audience(audience), rounds(rounds) {}

Configuration::Configuration(){};
void Configuration::printConfiguration() {
    cout << "Configuration: \n"
            "   name: " << name << endl <<
         "   playerCount: min: " << min << " max: " << max << endl <<
         "   audience: " << audience << endl <<
         "   rounds: " << rounds << endl;
}

