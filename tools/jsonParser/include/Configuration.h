//
// Created by dhall on 2020-10-08.
//

#ifndef SOCIAL_GAMING_CONFIGURATION_H
#define SOCIAL_GAMING_CONFIGURATION_H

#include <unordered_map>
#include <boost/variant.hpp>
#include <iostream>

using namespace std;

template <typename T>

// for more generic setup
// requires input-choice
struct SettingKind {
  T value;
  string prompt;
};

struct PlayerCount {
    int min;
    int max;
};

class Settings {
  private:
    unordered_map<string,boost::variant<int, double, bool, string>> settingsMap;

  public:
    Settings(unordered_map<string,boost::variant<int, double, bool, string>> settingsMap);
};

class Configuration {
  private:
      string name;
      PlayerCount playerCount;
      bool audience;
      Settings setup; //have set up class instead
      // data that may be uploaded by the owner for quiz based games ?

  public:
      Configuration(string name, int min, int max, bool audience, Settings setup);
      string getName();
      PlayerCount getPlayerCount();
      bool isAudible();
      Settings getSettings();
      void printConfiguration();
};


#endif //SOCIAL_GAMING_CONFIGURATION_H
