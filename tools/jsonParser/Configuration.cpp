#include "Configuration.h"
#include <iostream>

// Settings
Settings::Settings(unordered_map<string, GameVariant> settingsMap) : settingsMap(settingsMap){}

//needs to use variant :)
void Settings::printSettings(){
  cout << "   Set Up: \n";
  for ( auto itrr : this->settingsMap)
  {
    cout << "     " << itrr.first ;
    boost::apply_visitor( printVariant() , itrr.second );
  }
}

GameVariant Settings::getAtKey(string key){
  return this->settingsMap[key];
}


// Configuration
Configuration::Configuration(string name, int min, int max, bool audience, Settings setup)
    : name(name), playerCount({min, max}), audience(audience), setup(setup){}


void Configuration::print() {
    cout << "Configuration: \n"
            "   name: " << name << endl <<
         "   playerCount: min: " << playerCount.min << " max: " << playerCount.max << endl <<
         "   audience: " << audience << endl;
         setup.printSettings();

}

string Configuration::getName() {
    return name;
}

Settings Configuration::getSetUp() {
    return setup;
}

PlayerCount Configuration::getPlayerCount() {
    return playerCount;
}

bool Configuration::isAudible(){
    return audience;
}

GameVariant Configuration::getAtKey(string key){

  // check Settings;
  GameVariant value_at_key = this->setup.getAtKey(key);

  return value_at_key;

}
