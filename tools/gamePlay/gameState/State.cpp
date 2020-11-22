#include "State.h"

// constructor
State::State(vector<Player> playerList, Configuration configuration,
             Constants constants, Variables variables, PerPlayer perPlayer, PerAudience perAudience)
    : playerList(playerList), configuration(configuration), constants(constants), variables(variables),
    per_player(perPlayer), per_audience(perAudience){}

// Update State Functions
void State::UpdateState_Config(Configuration c){
  this->configuration = c;
}
void State::UpdateState_Constants(Constants c){
  this->constants = c;
}
void State::UpdateState_Variables(Variables v){
  this->variables = v;
}
void State::UpdateState_PerPlayer(PerPlayer pp){
  this->per_player = pp;
}
void State::UpdateState_PerAudience(PerAudience pa){
  this->per_audience = pa;
}
void State::UpdateState_PlayersList(Player& p){
  this->playerList.push_back(p);
}

// Get from State Functions
vector<Player> State::getPlayers() {
  return playerList;
}
vector<Player> State::getWinners() {
  return winnerList;
}
Configuration State::getConfiguration(){
  return configuration;
}
Constants State::getConstants(){
  return constants;
}

// unfinished
// Replace with State Value Functions
// ignores the unimplemented functions for now
vector<GameVariant> State::getStateList(string input){

  vector<GameVariant> result;

  // we can get configuration.some_key for now
  if( input.find("configuration") != string::npos){
    size_t pos = input.find(".")+1;
    string substr_input = input.substr(pos, input.length());
    size_t nextPos = substr_input.find(".");
    string config_key = substr_input.substr(0, nextPos);
    
    GameVariant value = this->configuration.getAtKey(config_key);
    result.push_back(value);

  }
  else if( input.find("constants") != string::npos){
    // none in rockPaperScissors
  }
  else if( input.find("variables") != string::npos){
        // none in rockPaperScissors
  }
  else if( input.find("per-player") != string::npos){
        // none in rockPaperScissors
  }
  else if( input.find("per-audience") != string::npos){
        // none in rockPaperScissors
  }
  else {
    // search within constants
    // size_t pos = input.find(".")+1;
    // string key = input.substr(input.begin(), pos);

    // key for key in various costants
    GameVariant value = this->constants.getAtKey(input);
    result.push_back(value);

    //search within variables

    // search within per-player, per-audience

  }
  // value.replace(open, close, "VARIABLE");
  return result;
}

// others
void State::print(){
  this->configuration.print();
  this->constants.print();
  this->variables.print();
  this->per_player.print();
  this->per_audience.print();
  return;
}
