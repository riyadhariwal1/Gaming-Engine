#ifndef SOCIAL_GAMING_PARSER_H
#define SOCIAL_GAMING_PARSER_H

#include <boost/variant.hpp>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <vector>

using namespace std;
using json = nlohmann::json;

// might replace unordered-map -> string with these
struct GameKey {
    string settings;
    string constant;
    string variables;
};
typedef boost::variant<unordered_map<string,string>, int, double, bool, string> ListType;

// should have vector of ListType instead of unordered_map
typedef boost::variant<unordered_map<string,string>, int, double, bool, string, vector<unordered_map<string,string>>> GameVariant;

unordered_map<string,GameVariant> jsonToMap(json map);

#endif //SOCIAL_GAMING_LOADER_H
