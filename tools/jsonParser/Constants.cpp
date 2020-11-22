#include "Constants.h"

Constants::Constants(unordered_map<string,GameVariant> constantsMap)
 : constantsMap(constantsMap) {};

void Constants::print(){
  cout << "Constants: \n";
  for ( auto itrr : this->constantsMap)
  {
    cout << "     " << itrr.first ;
    boost::apply_visitor( printVariant() , itrr.second );
  }
}

GameVariant Constants::getAtKey(string key){
  this->constantsMap[key];
}
