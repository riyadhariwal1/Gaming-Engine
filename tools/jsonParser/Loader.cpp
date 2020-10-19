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

void globalMessageRule (json rule)
{
    cout << " im in global" << endl;
    cout << rule.dump() << endl;

    string ruleTest = rule["value"].dump();
    GlobalMessage gm(ruleTest);
    gm.execute();

    cout << "\n";

}

void addRule (json rule)
{
  cout << " im in add" << endl;
  // example player to be removed with
  // rule["to"] when real players are used
  string exampleName = "Jason";
  Player sample_player(exampleName);
  sample_player.printPlayer();

  AddRule newWinForPlayer(sample_player, rule["value"]);
  sample_player.printPlayer();

  cout << "\n";
}

void inputChoiceRule(json rule)
{
    cout << " im in input" << endl;

}
void discardRule (json rule)
{
    cout << " im in discard" << endl;
}

void whenRule (json rule)
{
    cout << " im in when" << endl;

}
// void parallelForRule (json rule)
// {
//     cout << " im in parrallel" << endl;

//      json rules = rule["rules"];
//      for (const json rule :rules)
//      {
//         auto ruleName = rule.at("rule").get<string>();
//         cout << ruleName << endl;
//         if (ruleName == "global-message")
//         {
//             globalMessageRule(rule);
//         }
//         else if (ruleName == "foreach")
//         {
//             //forEachRule(rule);
//         }
//         else if (ruleName == "parallelfor")
//         {
//             parallelForRule(rule);
//         }
//         else if (ruleName == "discard")
//         {
//             discardRule(rule);
//         }
//         else if (ruleName == "when")
//         {
//             whenRule(rule);
//         }
//         else if (ruleName =="input-choice")
//         {
//             inputChoiceRule(rule);
//         }
//      }
// }
void forEachRule(json element)
{
    class forEach;
    string list = element.at("list").get<string>();
    string ele = element.at("element").get<string>();

    json rules = element["rules"];
    int i = 0;

    for (const json rule :rules)
    {
        cout << i++ << endl;
        auto ruleName = rule.at("rule").get<string>();
        cout << ruleName << endl;

        if (ruleName == "global-message")
        {
            globalMessageRule(rule);
        }
        else if (ruleName == "foreach")
        {
            forEachRule(rule);
        }
        else if (ruleName == "parallelfor")
        {
            forEachRule(rule);
        }
        else if (ruleName == "discard")
        {
            discardRule(rule);
        }
        else if (ruleName == "add")
        {
          addRule(rule);
        }
        else if (ruleName == "when")
        {
            whenRule(rule);
        }
        else if (ruleName =="input-choice")
        {
            inputChoiceRule(rule);
        }
    }
}


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


    // rules
    // basics -- discard, global messagae, extend
    // when, input-choice, add,
    // parellelfor, foreach

    /*json rule_parallelfor = rule_samples[0];
    json rule_input-choice = rule_samples[1];
    json rule_discard = rule_samples[2];
    json rule_foreach = rule_samples[3];
    json rule_when = rule_samples[4];
    json rule_add = rule_when["cases"][2]["rules"][1]["rules"][0];*/

    json rules = j["rules"];

    int i = 0;
    for (const json element :rules)
    {
        //cout << i++ << endl;
        auto rulesName = element.at("rule").get<string>();
        //cout << rulesName << endl;
        if(rulesName == "foreach")
        {
            forEachRule(element);
        }
        if (rulesName == "scores")
        {
            cout << "hahahaha" <<endl;
        }
    }
}
