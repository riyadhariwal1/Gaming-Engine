#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Constants.h"
#include "Variables.h"
#include <fstream>
#include <sstream>

using namespace std;
using json = nlohmann::json;

int main() {
    string filePath = "./rockPaperScissors.json";
    ifstream ifs(filePath);
    if (ifs.fail()){
        throw std::runtime_error("Cannot open Json file");
    }
    json j = json::parse(ifs);

    //config
    json config = j["configuration"];
    Configuration configuration = Configuration(config["name"], config["player count"]["min"],
                                                config["player count"]["max"], config["audience"], config["setup"]["Rounds"]);
    configuration.printConfiguration();

    //constants
    json constantsArr = j["constants"]["weapons"];
    Constants constant;
    for (const auto &element : constantsArr){
        auto name = element.at("name").get<string>();
        auto beats = element.at("beats").get<string>();
        Weapon temp(name, beats);
        constant.addWeapon(temp);
    }
    constant.print();

    //variable
    json variable = j["variables"]["winners"];
    Variables var;
    for (const auto &element : variable){
        string winner = element.get<string>();
        var.addWinner(winner);
    }

    var.print();

    // rules
    // basics -- discard, global messgae, extend
    // when, input-choice, add,
    // parellelfor, foreach
    json rules = j["rules"]























}
