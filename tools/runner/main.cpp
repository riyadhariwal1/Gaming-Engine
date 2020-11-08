#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Constants.h"
#include "Variables.h"
#include <fstream>
#include <sstream>
#include "Rule.h"
#include "GlobalMessage.h"
#include "Extend.h"
#include "When.h"
#include "Discard.h"
#include "ForEach.h"
#include "ParallelFor.h"
#include "Player.h"
#include "InputChoice.h"
#include "Scores.h"
#include "Add.h"
#include "Loader.h"
#include "State.h"
#include "Game.h"
#include "Parser.h"
#include <string>
#include <typeinfo>


using namespace std;
using json = nlohmann::json;

int main()
{
    string filePath = "rockPaperScissors.json";
    ifstream ifs(filePath, std::ifstream::binary);
    if (ifs.fail())
    {
        throw std::runtime_error("Cannot open Json file");
    }

    json GAMEJSON = json::parse(ifs);

    // EXTRACT GAME SPECIFICATION STRUCTURE
    json config = GAMEJSON["configuration"];
    json constants = GAMEJSON["constants"];
    json variables = GAMEJSON["variables"];
    json per_player = GAMEJSON["per-player"];
    json per_audience = GAMEJSON["per-audience"];
    json rules = GAMEJSON["rules"];

    // EXTRACT STATE
    //config
    Settings game_settings(jsonToMap(config["setup"]));
    Configuration configuration = Configuration(config["name"], config["player count"]["min"],
                                                config["player count"]["max"], config["audience"], game_settings);
    configuration.printConfiguration();

    //constants
    Constants constant(jsonToMap(constants));
    constant.print();


    // for (const auto &element : constant_weapons)
    // {
    //     auto name = element.at("name").get<string>();
    //     auto beats = element.at("beats").get<string>();
    //     Weapon temp(name, beats);
    //     constant.addWeapon(temp);
    // }
    // constant.print();

/*
    //variables
    json winners = variables["winners"];
    Variables var;
    for (const auto &element : winners)
    {
        string winner = element.get<string>();
        var.addWinner(winner);
    }
    var.print();
    cout << "\n\n"
         << endl;

    // rules!
    vector<Rule *> allRule;
    Loader loader;
    int i = 0;
    for (const json element : rules)
    {
        //cout << i++ << endl;
        auto rulesName = element.at("rule").get<string>();
        //cout << rulesName << endl;
        if (rulesName == "foreach")
        {
            ForEachRule *ruleIndex = loader.forEachRule(element);
            allRule.push_back(ruleIndex);
        }

        else if (rulesName == "scores")
        {
            ScoreRule *ruleIndex = loader.scoreRule(element);
            allRule.push_back(ruleIndex);
        }
    }
    for (int i = 0; i < allRule.size(); i++)
    {
        allRule[i]->print();
    }

    // Loader loader;
    // loader.forEachRule(j);
    // //game test ! missing ruleList
    AllPlayers allPlayer;
    State state(allPlayer.getList(), configuration, constant, var);

    Game game(state, allRule);*/
}
