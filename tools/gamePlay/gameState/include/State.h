#ifndef SOCIAL_GAMING_STATE_H
#define SOCIAL_GAMING_STATE_H

#include "Player.h"
#include "Constants.h"
#include "Configuration.h"
#include "Variables.h"
#include "PlayerSetup.h"

class State {
private:
  vector<Player> playerList;
  vector<Player> winnerList;
  Configuration configuration;
  Constants constants;
  Variables variables;
  PerPlayer per_player;
  PerAudience per_audience;
  bool isGameEnd;

public:
  State(vector<Player> playerList, Configuration configuration,
        Constants constants, Variables variables, PerPlayer per_Player, PerAudience per_Audience);

  vector<Player> getPlayers();
  vector<Player> getWinners();
  vector<GameVariant> getRounds();
  Configuration getConfiguration();
  Constants getConstants();
  Variables getVariables();
  PerPlayer getPlayerSetp();
  PerAudience getAudienceSetup();

  // update state
  void UpdateState_Config(Configuration);
  void UpdateState_Constants(Constants);
  void UpdateState_Variables(Variables);
  void UpdateState_PerPlayer(PerPlayer);
  void UpdateState_PerAudience(PerAudience);
  void UpdateState_PlayersList(Player&);
  void UpdateState_WinnersList(Player& p);

  // string manipulations or condition checks
  vector<GameVariant> getStateList(string);
  bool checkCondition(string);
  // string manipulations or condition checks
  GameVariant getFromState(string);
  

  void print();


};
#endif
