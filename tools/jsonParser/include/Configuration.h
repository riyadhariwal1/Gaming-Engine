//
// Created by dhall on 2020-10-08.
//

#ifndef SOCIAL_GAMING_CONFIGURATION_H
#define SOCIAL_GAMING_CONFIGURATION_H

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
    void UpdateSetting(string keyToUpdate, GameVariant valueToUpdate);
    GameVariant getAtKey(string);
    bool checkIfKeyExists(string);
};

class Configuration {
  private:

    // this might need refactoring as unordered_map<string, GameVariant>
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

      GameVariant getAtKey(string);
      bool checkIfKeyExists(string);
      void print();
};


#endif //SOCIAL_GAMING_CONFIGURATION_H
