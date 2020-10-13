#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include <fstream>
#include <sstream>

using namespace std;
using json = nlohmann::json;

int main() {
    string filePath = "rockPaperScissors.json";
    ifstream ifs(filePath);
    if (ifs.fail())
    {
        throw std::runtime_error("Cannot open Json file");
    }
    json j = json::parse(ifs);

    //config
    json config = j["configuration"];
    Configuration configuration = Configuration(config["name"], config["player count"]["min"],
                                                config["player count"]["max"], config["audience"], config["setup"]["Rounds"]);
    configuration.printConfiguration();
}


