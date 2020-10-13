#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Configuration.cpp"

#include "Constants.cpp"
#include <fstream>
#include <sstream>

using namespace std;
using json = nlohmann::json;

int main() {

    string filePath = "rockPaperScissors.json";
    ifstream ifs(filePath, std::ifstream::binary);
   
    json j = json::parse(ifs);
    json configuration = j["configuration"];
    
    Configuration config;
    config.from_json(configuration);
    config.printConfiguration();

    json constantsArr = j["constants"]["weapons"];


    Constants constants;
    constants.from_json(constantsArr);
    constants.print();

}


