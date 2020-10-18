#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Constants.h"
#include "Variables.h"
#include <fstream>
#include <sstream>

#include "GlobalMessage.h"
#include "Player.h"
#include "Add.h"

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
    // basics -- discard, global messagae, extend
    // when, input-choice, add,
    // parellelfor, foreach

    /*json rule_parallelfor = rule_samples[1];
    json rule_input-choice = rule_samples[2];
    json rule_discard = rule_samples[3];
    json rule_foreach = rule_samples[4];
    json rule_when = rule_samples[5];
    json rule_add = rule_when["cases"][2]["rules"][1]["rules"][0];*/
    cout << "\n";

    json rules = j["rules"];
    json rule_samples = rules[0]["rules"];

    // global message
    json rule_GM = rule_samples[0];
    cout << "Test Rule:" << rule_GM.dump() << endl;

    string ruleTest1 = rule_GM.dump();
    GlobalMessage gm(ruleTest1);
    gm.execute();

    cout << "\n";

    // add
    json rule_when = rule_samples[4];
    json rule_add = rule_when["cases"][2]["rules"][1]["rules"][0];
    cout << "Test Rule:" << rule_add.dump() << endl;

    string name = "Jason";
    Player player1(name);
    player1.printPlayer();
    string ruleTest2 = rule_add.dump();
    AddRule newWinForPlayer(player1, 1);
    player1.printPlayer();

    cout << "\n";

    //

}
