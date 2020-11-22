//
// Created by SUNAINA PAUDEL
//
#include "PlayerSetup.h"


PerPlayer::PerPlayer(unordered_map<string,GameVariant> playerMap)
 : playerMap(playerMap) {};

void PerPlayer::print(){
  cout << "Per_Player: \n";
  for ( auto itrr : this->playerMap)
  {
    cout << "     " << itrr.first ;
    boost::apply_visitor( printVariant() , itrr.second );
  }
}

PerAudience::PerAudience(unordered_map<string,GameVariant> audienceMap)
 : audienceMap(audienceMap) {};

void PerAudience::print(){
  cout << "Per_Audience: \n";
  for ( auto itrr : this->audienceMap)
  {
    cout << "     " << itrr.first ;
    boost::apply_visitor( printVariant() , itrr.second );
  }
}
