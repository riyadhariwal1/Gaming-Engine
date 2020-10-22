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

void AllPlayers::addPlayer(Player player) {
    playerList.push_back(player);
}

vector<Player> AllPlayers::getList(){
    //test:
    string name = "test!";
    Player player(name);
    addPlayer(player);

    return playerList;
}