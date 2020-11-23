#include "State.h"
//#include <bits/stdc++.h>

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
void State::UpdateState_WinnersList(Player& p){
  this->winnerList.push_back(p);
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

// second tokens can just be taken out of first tokens
GameVariant State::getFromState(string input){

  GameVariant result;
  vector<string> tokens = splitString(input);

    string first = tokens[0];
    if(first=="configuration"){
      //go to second word
      string second = tokens[1];
      result = this->configuration.getAtKey(second);
    }
    else {

      if(this->constants.checkIfKeyExists(first)){
        result = this->constants.getAtKey(first);
        if(tokens.size() > 1){
          string second = tokens[1];
          // find the nested value like weapon."names"
        }
      }
      else if (this->variables.checkIfKeyExists(first)){
        result = this->variables.getAtKey(first);
        if(tokens.size() > 1){
          string second = tokens[1];
          // find the nested value like weapon."names"
        }
      }
    }


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
