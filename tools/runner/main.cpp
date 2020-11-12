#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Constants.h"
#include "Variables.h"
#include <fstream>
#include <sstream>
#include "AstNode.h"
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
#include "PlayerSetup.h"
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
    configuration.print();

    //constants
    Constants constant(jsonToMap(constants));
    constant.print();

    //variables
    Variables variable(jsonToMap(variables));
    variable.print();


    //players
    PerPlayer perPlayer(jsonToMap(per_player));
    perPlayer.print();

    PerAudience perAudience(jsonToMap(per_audience));
    perAudience.print();

    // Loop through the rules!
    json rules = j["rules"];
    vector<AstNode*> allRule;


    AllPlayers allPlayer;

    State state(allPlayer.getList(), configuration, constant, variable, perPlayer, perAudience);

    // rules!
    // change this up using AST
    vector<Rule *> allRule;
    Loader loader;
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

    //Start Game
    Game game(state, allRule);
}
