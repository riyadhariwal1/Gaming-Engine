#include "Configuration.h"

Settings::Settings(unordered_map<string,boost::variant<int, double, bool, string>> settingsMap) : settingsMap(settingsMap){}

void Settings::printSettings(){
  cout << "   Set Up: \n";
  for ( auto itrr : this->settingsMap)
  {
    cout << "       " << itrr.first << ": " << itrr.second << endl;
  }
}

Configuration::Configuration(string name, int min, int max, bool audience, Settings setup)
    : name(name), playerCount({min, max}), audience(audience), setup(setup){}


void Configuration::printConfiguration() {
    cout << "Configuration: \n"
            "   name: " << name << endl <<
         "   playerCount: min: " << playerCount.min << " max: " << playerCount.max << endl <<
         "   audience: " << audience << endl;
         setup.printSettings();

}

string Configuration::getName() {
    return name;
}

/*SetUp Configuration::getSetUp() {
    return setup;
}*/

PlayerCount Configuration::getPlayerCount() {
    return playerCount;
}

bool Configuration::isAudible(){
    return audience;
}
