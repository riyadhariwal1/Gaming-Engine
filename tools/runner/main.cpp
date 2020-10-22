#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Constants.h"
#include "Variables.h"
#include <fstream>
#include <sstream>
#include "Game.h"
#include "GlobalMessage.h"
#include "Player.h"
#include "Add.h"
#include "Loader.h"

using namespace std;
using json = nlohmann::json;

int main() {
    string filePath = "rockPaperScissors.json";
    ifstream ifs(filePath, std::ifstream::binary);
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
    cout << "\n\n" <<endl;

    // Loop through the rules!
    Loader loader;
    loader.forEachRule(j);


    //game test ! missing ruleList
    AllPlayers allPlayer;
    Game game(allPlayer.getList(), configuration, constant, var);
}