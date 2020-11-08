//
// Created by dhall on 2020-10-08.
//

#ifndef SOCIAL_GAMING_CONFIGURATION_H
#define SOCIAL_GAMING_CONFIGURATION_H

#include <unordered_map>
#include <iostream>
#include "Parser.h"

using namespace std;


struct PlayerCount {
    int min;
    int max;
};


// settings can be changed by users
class Settings {
  private:
    unordered_map<string, GameVariant> settingsMap;

  public:
    Settings(unordered_map<string, GameVariant> settingsMap);
    void printSettings();
    // update a setting
    //void UpdateSetting(string keyToUpdate, boost::variant<unordered_map<string,string>, int, double, bool, string>> valueToUpdate);
};

class Configuration {
  private:
      string name;
      PlayerCount playerCount;
      bool audience;
      Settings setup;
      // data that may be uploaded by the owner for quiz based games ?

  public:
      Configuration(string name, int min, int max, bool audience, Settings setup);
      string getName();
      PlayerCount getPlayerCount();
      bool isAudible();
      Settings getSetUp();
      void printConfiguration();
};


#endif //SOCIAL_GAMING_CONFIGURATION_H
