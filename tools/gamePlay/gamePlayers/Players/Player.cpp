#include "Player.h"
#include <iostream>

Player::Player(string& name): name(name){
  this->id=1001;
  this->gameWins=0;
}

void Player::playerWins(int count) {
  this->gameWins+=count;
}

void Player::printPlayer(){
  cout << this->name << " has points: " << this->gameWins << endl;
}
