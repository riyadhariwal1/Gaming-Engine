#include "Parser.h"
#include <string>
#include <iostream>

unordered_map<string,GameVariant> jsonToMap(json jsonMap){

  unordered_map<string,GameVariant> jsonToGameVal;

  for ( auto& itrr : jsonMap.items())
  {
    string key = itrr.key();

    // type=bool
    if (jsonMap[key].type() == json::value_t::boolean) {
      jsonToGameVal[key] = jsonMap[key].get<bool>();
    }
    //type=number
    else if ((jsonMap[key].type() == json::value_t::number_unsigned) ||
      (jsonMap[key].type() == json::value_t::number_integer)) {
      jsonToGameVal[key] = jsonMap[key].get<int>();
    }
    //type=double
    else if (jsonMap[key].type() == json::value_t::number_float) {
      jsonToGameVal[key] = jsonMap[key].get<double>();
    }
    //type=string
    else if (jsonMap[key].type() == json::value_t::string) {
      jsonToGameVal[key] = jsonMap[key].get<string>();
    }
    //type=object
    else if (jsonMap[key].type() == json::value_t::object) {
      jsonToGameVal[key] = jsonMap[key].get<unordered_map<string,string>>();
    }

  }

  return jsonToGameVal;

}
