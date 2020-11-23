#ifndef SOCIAL_GAMING_PARSER_H
#define SOCIAL_GAMING_PARSER_H

#include <nlohmann/json.hpp>
#include "GameVariant.h"

using namespace std;
using json = nlohmann::json;

// json_conversion_into_gameVariant
unordered_map<string,GameVariant> jsonToMap(json map);

string replaceInString(string input, string value);

#endif
