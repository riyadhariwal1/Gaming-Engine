#include "State.h"

// constructor
State::State(vector<Player> playerList, Configuration configuration,
             Constants constants, Variables variables, PerPlayer perPlayer, PerAudience perAudience)
    : playerList(playerList), configuration(configuration), constants(constants), variables(variables),
    per_player(perPlayer), per_audience(perAudience), currentRound(1)
    {}

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
void State::incrementCurrentRound()
{
  currentRound++;
}

void State::UpdateState_WinnersList(Player& p){
  this->winnerList.push_back(p);
}
void State::incrementCurrentRound()
{
  currentRound++;
}
vector<GameVariant> State::getRounds()
{
  return rounds;
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
vector<GameVariant> State::getRounds()
{
  return rounds;
}
int State::getCurrentRounds()
{
  return currentRound;
}

// only handles rockPaperScissors file for now
// Interpreter will handle the functions and such
vector<string> splitString(string str){
  vector<string> substrings;
  string word ="";
  for (auto c : str){
    if( c != '.' ){
      word+=c;
    }
    else {
      substrings.push_back(word);
      word="";
    }
  }
  substrings.push_back(word);
  return substrings;
}
vector<GameVariant> State::getStateList(string input){

  vector<GameVariant> result;

  if( input.find("configuration") != string::npos){
    size_t pos = input.find(".")+1;
    string substr_input = input.substr(pos, input.length());
    size_t nextPos = substr_input.find(".");
    string config_key = substr_input.substr(0, nextPos);
    GameVariant value = this->configuration.getAtKey(config_key);
    
    for(int i = 1; i <= boost::get<int>(value); i++)
    {
      result.push_back(i);
    }

    rounds = result;
  }
  else if( input.find("round") != string::npos){
    return this->getRounds();
  }

  return result;

}


// getFromState's job is only to retreive the GameVariant Value from State
// no lovel of interpretation here
GameVariant State::getFromState(string input){

  GameVariant result;
  vector<string> tokens = splitString(input);

    string first = tokens[0];
    if(first=="configuration"){
      //go to second word
      string second = tokens[1];
      result = this->configuration.getAtKey(second);
    }
    else if(first=="constants"){
      //go to second word
      string second = tokens[1];
      result = this->constants.getAtKey(second);
    }
    else if(first=="variables"){
      //go to second word
      string second = tokens[1];
      result = this->variables.getAtKey(second);
    }
    else if(first=="per_player"){
      //go to second word
      string second = tokens[1];
      result = this->per_player.getAtKey(second);
    }
    else if(first=="per_audience"){
      //go to second word
      string second = tokens[1];
      result = this->per_audience.getAtKey(second);
    }
    else {

      if(this->constants.checkIfKeyExists(first)){
        result = this->constants.getAtKey(first);
      }
      else if (this->variables.checkIfKeyExists(first)){
        result = this->variables.getAtKey(first);
      }
      else if (this->configuration.checkIfKeyExists(first)){
        result = this->configuration.getAtKey(first);
      }
      else if (this->per_player.checkIfKeyExists(first)){
        result = this->per_player.getAtKey(first);
      }
      else if (this->per_audience.checkIfKeyExists(first)){
        result = this->per_audience.getAtKey(first);
      }
    }


  return result;
}

// others
// void State::print(){
//   this->configuration.print();
//   this->constants.print();
//   this->variables.print();
//   this->per_player.print();
//   this->per_audience.print();
//   return;
// }
