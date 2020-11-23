#include "Variables.h"

Variables::Variables(unordered_map<string,GameVariant> variablesMap)
 : variablesMap(variablesMap) {};

//might want to make print generic
void Variables::print(){
  cout << "Variables: \n";
  for ( auto itrr : this->variablesMap)
  {
    cout << "     " << itrr.first ;
    boost::apply_visitor( printVariant() , itrr.second );
  }
}

GameVariant Variables::getAtKey(string key){
  GameVariant value_at_key = this->variablesMap[key];
  return value_at_key;
}

bool Variables::checkIfKeyExists(string key){
 if(this->variablesMap.count(key)>0){
   return true;
 }
 return false;
}
