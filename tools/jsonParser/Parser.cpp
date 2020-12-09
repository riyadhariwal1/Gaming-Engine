#include "Parser.h"


GameVariant
convertJson(json::value_t jsonType, json value){
  GameVariant newValue;
  switch (jsonType) {
    case json::value_t::boolean:
      newValue = value.get<bool>();
      break;
    case json::value_t::number_integer:
    case json::value_t::number_unsigned:
      newValue = value.get<int>();
      break;
    case json::value_t::number_float:
      newValue= value.get<float>();
      break;
    case json::value_t::object:
      newValue = value.get<unordered_map<string,string>>();
      break;
    default:
      newValue = value.get<string>();
  }

  return newValue;
}


unordered_map<string,GameVariant>
jsonToMap(json jsonMap){

  unordered_map<string,GameVariant> GameMap;
  for ( auto& itrr : jsonMap.items())
  {
    string key = itrr.key();

    if(jsonMap[key].type()==json::value_t::array){
      // extracting a vector from json
      vector<unordered_map<string,string>> vec;
      for(auto val : jsonMap[key]){

        switch(val.type()) {
          case json::value_t::object:
            vec.push_back(val.get<unordered_map<string,string>>());
            break;
          default:
            cout << "[ error ]: Json Vector is not type map<string,string>";
        }

      }
      GameMap[key] = vec;

    } else {

      GameMap[key] = convertJson(jsonMap[key].type(),jsonMap[key] );

      }
  }

  return GameMap;

}
