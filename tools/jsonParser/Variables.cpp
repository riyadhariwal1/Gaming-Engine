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
