//
// Created by SUNAINA PAUDEL
//

#ifndef SOCIAL_GAMING_PLAYER_SETUP_H
#define SOCIAL_GAMING_PLAYER_SETUP_H

#include <boost/variant.hpp>
#include <iostream>
#include <vector>
#include "Parser.h"


class PerPlayer{
  private:
      unordered_map<string,GameVariant> playerMap;

  public:
      PerPlayer(unordered_map<string,GameVariant> playerMap);
      void print();
};

class PerAudience {
  private:
      unordered_map<string,GameVariant> audienceMap;

  public:
      PerAudience(unordered_map<string,GameVariant> audienceMap);
      void print();
  };

#endif
