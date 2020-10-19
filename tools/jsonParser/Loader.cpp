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

/* DECLARATIONS */
void forEachRule(json element);


/* -- */
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
    //cout << rule << "\n" << endl;

    json conditions = rule["cases"];
    for (const json element : conditions) {
      cout << element << endl;
      // parse the given condition
      // if condition is true: extract element["rules"]
      if (element["condition"] == true){
        forEachRule(element);
      }
    }
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

// Note: we cannot treat this recursive function that
// loops through all rules the same as rule=="foreach"
// "foreach" class will need to receive list + element
// and apply some rules specifically to that
void forEachRule(json element)
{
    //class forEach;

    json rules = element["rules"];
    int i = 0;

    for (const json rule :rules)
    {
        cout << i++ << endl;
        auto ruleName = rule["rule"];
        cout << ruleName << endl;

      if (ruleName == "global-message")
        {
            globalMessageRule(rule);
        }
        else if (ruleName == "foreach")
        {
            auto list = element["list"];
            auto ele = element["element"];
            // apply the upcoming rules to these lists/element
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
        else if (ruleName == "scores")
        {
            cout << "hahahaha" <<endl;
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
    cout << "\n\n" <<endl;

    // Loop through the rules!
    forEachRule(j);

}
