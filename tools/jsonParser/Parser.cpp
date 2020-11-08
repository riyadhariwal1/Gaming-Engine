#include "Parser.h"
#include <iostream>

unordered_map<string,GameVariant> jsonToMap(json jsonMap){

  // GameMap is a map of setup || constants || variables
  unordered_map<string,GameVariant> GameMap;

  for ( auto& itrr : jsonMap.items())
  {
    string key = itrr.key();

    switch (jsonMap[key].type()) {
      // type=bool
      case json::value_t::boolean:
        GameMap[key] = jsonMap[key].get<bool>();
        break;
      //type=integer
      case json::value_t::number_integer:
      case json::value_t::number_unsigned:
        GameMap[key] = jsonMap[key].get<int>();
        break;
      //type=double
      case json::value_t::number_float:
        GameMap[key] = jsonMap[key].get<double>();
        break;
      //type=string
      case json::value_t::string:
        GameMap[key] = jsonMap[key].get<string>();
        break;
      //type=map
      case json::value_t::object:
        GameMap[key] = jsonMap[key].get<unordered_map<string,string>>();
        break;
      //type=list
      // need to handle all types when extracting values
      case json::value_t::array:
      {
        vector<unordered_map<string,string>> vec;
        for(auto val : jsonMap[key]){
          switch(val.type()) {
            case json::value_t::object:
              vec.push_back(val.get<unordered_map<string,string>>());
              break;
            // case json::value_t::number_integer:
            // case json::value_t::number_unsigned:
            //   vec.push_back(val.get<int>());
            //   break;
            // case json::value_t::number_float:
            //   vec.push_back(val.get<double>());
            // case json::value_t::string:
            //   vec.push_back(val.get<string>());
            // case json::value_t::boolean:
            //   vec.push_back(val.get<bool>());
            default:
              cout << "";
          }
        }
        GameMap[key] = vec;
      }
        break;
      default:
        cout << "";
    }
  }

  return GameMap;

}
