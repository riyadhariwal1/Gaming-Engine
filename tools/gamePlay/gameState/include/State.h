#ifndef SOCIAL_GAMING_STATE_H
#define SOCIAL_GAMING_STATE_H

#include "Player.h"
#include "Constants.h"
#include "Configuration.h"
#include "Variables.h"

class State
{
  private:
      vector<Player> playerList;
      vector<Player> winnerList;
      Configuration configuration;
      Constants constants;
      Variables variables;
      bool isGameEnd;

  public:
      State(vector<Player> playerList, Configuration configuration, Constants constants, Variables variables);
      auto getPlayers();
      Configuration getConfiguration();
      Constants getConstants();
      auto findByName(string);


};
#endif
