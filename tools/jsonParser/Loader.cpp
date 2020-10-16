#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Constants.h"
#include "Variables.h"
#include <fstream>
#include <sstream>

using namespace std;
using json = nlohmann::json;

void globalMessageRule (json rule)
{
    cout << " im in global" << endl;
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
void forEachRule(json element )
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

    json j = json::parse(ifs);

    // //config
    // json config = j["configuration"];
    // Configuration configuration = Configuration(config["name"], config["player count"]["min"],
    //                                             config["player count"]["max"], config["audience"], config["setup"]["Rounds"]);
    // configuration.printConfiguration();

    // //constants
    // json constantsArr = j["constants"]["weapons"];
    // Constants constant; 
    // for (const auto &element : constantsArr)
    // {
    //     auto name = element.at("name").get<string>();
    //     auto beats = element.at("beats").get<string>();
    //     Weapon temp(name, beats);
    //     constant.addWeapon(temp);
    // }
    // constant.print();
    // //variable
    // json variable = j["variables"]["winners"];
    // Variables var;
    // for (const auto&element : variable)
    // {
    //     string winner = element.get<string>();
    //     var.addWinner(winner);
    // }
    // var.print();

    // rules 
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


