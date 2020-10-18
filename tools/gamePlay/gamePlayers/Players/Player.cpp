#include "Player.h"

Player::Player(string& name): name(name){
  this->id=1001;
  this->gameWins=0;
}

void Player::playerWins() {
  this->gameWins++;
}
