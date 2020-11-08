#include "Configuration.h"

// Settings
Settings::Settings(unordered_map<string, GameVariant> settingsMap) : settingsMap(settingsMap){}

//needs to use variant :)
void Settings::printSettings(){
  cout << "   Set Up: \n";
  for ( auto itrr : this->settingsMap)
  {
    cout << "       " << itrr.first;
    switch(itrr.second.which()){
      case 0:
        cout << "\n";
        for (auto i : boost::get<unordered_map<string,string>>(itrr.second)){
          cout << "         "<< i.first << ":" << i.second << endl;
        }
        break;
      case 1:
        cout << ": " << boost::get<int>(itrr.second) << endl;
        break;
      case 2:
        cout << ": " << boost::get<double>(itrr.second) << endl;
        break;
      case 3:
        cout << ": " << boost::get<bool>(itrr.second) << endl;
        break;
      case 4:
        cout << ": " << boost::get<string>(itrr.second) << endl;
        break;
      default:
        cout << "" << endl;
    }

  }
}


// Configuration
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

Settings Configuration::getSetUp() {
    return setup;
}

PlayerCount Configuration::getPlayerCount() {
    return playerCount;
}

bool Configuration::isAudible(){
    return audience;
}
