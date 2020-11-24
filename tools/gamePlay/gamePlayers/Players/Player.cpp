#include "Player.h"
#include <iostream>

// Players Class
Player::Player(){
  this->id=1001;
  this->gameWins=0;
  this->name = "no-name";
}
Player::Player(string name): name(name){
  this->id=1001;
  this->gameWins=0;
}

void Player::playerWins(int count) {
  this->gameWins+=count;
}

void Player::printPlayer(){
  cout << this->name << " has points: " << this->gameWins << endl;
}

void Player::AddVariable(string givenKey, GameVariant givenValue){
  this->PlayerVariablesMap[givenKey] = givenValue;
}

// All-Players Classs
void AllPlayers::addPlayer(Player player) {
    this->playerList.push_back(player);
}

vector<Player> AllPlayers::getList(){
    return this->playerList;
}