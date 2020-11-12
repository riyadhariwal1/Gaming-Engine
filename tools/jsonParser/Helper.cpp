#include "Helper.h"

string replaceInString(string input, GameVariant value){

  size_t open = input.find("{");
  size_t close = input.find("}");

// shift through every boost type case 
  string to_replace = to_string(boost::get<int>(value));
  input.replace(open, close-open+1, to_replace);

  // element.someVar

  return input;
}
