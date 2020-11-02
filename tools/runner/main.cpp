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
#include <string>
#include <typeinfo>
#include <boost/variant.hpp>

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
    // config
    // extract setup
    json setup = config["setup"];
    unordered_map<string,boost::variant<int, double, bool, string>> config_setup;
    for ( auto& itrr : setup.items())
    {
      string key = itrr.key();
      if (setup[key].type() == json::value_t::boolean) {
        config_setup[key] = setup[key].get<bool>();
      }
      else if ((setup[key].type() == json::value_t::number_unsigned) ||
        (setup[key].type() == json::value_t::number_integer)) {
        config_setup[key] = setup[key].get<int>();

      }
      else if (setup[key].type() == json::value_t::number_float) {
        config_setup[key] = setup[key].get<double>();

      }
      else if (setup[key].type() == json::value_t::string) {
        config_setup[key] = setup[key].get<string>();
      }
      else if (setup[key].type() == json::value_t::object) {
        // still need to update for this 
        cout <<  setup[key]["Kind"];
        cout <<  setup[key]["Prompt"];
      }
    }

    Settings game_settings(config_setup);
    Configuration configuration = Configuration(config["name"], config["player count"]["min"],
                                                config["player count"]["max"], config["audience"], game_settings);
    configuration.printConfiguration();
/*
    //constants
    json constant_weapons = constants["weapons"];
    Constants constant;
    for (const auto &element : constant_weapons)
    {
        auto name = element.at("name").get<string>();
        auto beats = element.at("beats").get<string>();
        Weapon temp(name, beats);
        constant.addWeapon(temp);
    }
    constant.print();

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
