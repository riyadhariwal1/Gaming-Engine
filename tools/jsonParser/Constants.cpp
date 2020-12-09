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
  GameVariant value_at_key = this->constantsMap[key];
  return value_at_key;
}

bool Constants::checkIfKeyExists(string key){
 if(this->constantsMap.count(key)>0){
   return true;
 }
 return false;
}
