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

using namespace std;
using json = nlohmann::json;

/* DECLARATIONS */
ForEachRule* forEachRule(json element);

/* -- */
GlobalMessage *globalMessageRule(json rule)
{
    cout << "Im in golbal" << endl;
    GlobalMessage *globalMessage = new GlobalMessage(rule.at("value").get<string>());

    return globalMessage;
}

void addRule(json rule)
{
    //   cout << " im in add" << endl;
    //   // example player to be removed with
    //   // rule["to"] when real players are used
    //   string exampleName = "Jason";
    //   Player sample_player(exampleName);
    //   sample_player.printPlayer();

    //   AddRule newWinForPlayer(sample_player, rule["value"]);
    //   sample_player.printPlayer();

    //   cout << "\n";
}

InputChoiceRule *inputChoiceRule(json rule)
{
    //cout << "Im in input" << endl;

    InputChoiceRule *input = new InputChoiceRule(rule.at("prompt").get<string>(),
                                                 rule.at("choices").get<string>(),
                                                 rule.at("result").get<string>(),
                                                 rule.at("to").get<string>());

    return input;
}
DiscardRule *discardRule(json rule)
{
    //cout << "Im in discard" << endl;
    DiscardRule *discard = new DiscardRule(rule.at("from").get<string>(), rule.at("count").get<string>());

    return discard;
}
ExtendRule* extendRule (json rule)
{
    //cout << "Im in extend" << endl;
    ExtendRule* extend = new ExtendRule(rule.at("list").get<string>(), rule.at("target").get<string>());
    return extend;
}

WhenRule *whenRule(json rule)
{
    //cout << " im in when" << endl;
    //cout << rule << "\n" << endl;

    json conditions = rule["cases"];
    
    WhenRule *whenRule = new WhenRule();
    for (const json ele : conditions)
    {
        string check = ele["condition"].dump();
        Case* cas = new Case(check);
        

        json ruleList = ele["rules"];

        for (const json element : ruleList)
        {
            auto ruleName = element.at("rule").get<string>();
            if (ruleName == "extend")
            {
                ExtendRule* ruleIndex = extendRule(element);
                cas -> addRule(ruleIndex);
            }
            else if (ruleName == "global-message")
            {
                GlobalMessage *ruleIndex = globalMessageRule(element);
                cas -> addRule(ruleIndex);
            }
            else if (ruleName == "foreach")
            {      
                ForEachRule *ruleIndex = forEachRule(element);
                cas -> addRule(ruleIndex);
            }
            
        }
        cout << endl;
        whenRule -> addCase(cas);
        //parse the given condition
        //if condition is true: extract element["rules"]
    }
    //whenRule->print();
    return whenRule;
}
ScoreRule * scoreRule(json rule)
{
    ScoreRule* scoreRule = new ScoreRule (rule.at("score").get<string>(), rule.at("ascending").get<bool>());
    return scoreRule;

}
ParallelFor *parallelForRule(json rule)
{
    //cout << " im in parrallel" << endl;
    ParallelFor *parallelFor = new ParallelFor(rule.at("list").get<string>(), rule.at("element").get<string>());
    json rules = rule["rules"];
    for (const json rule : rules)
    {
        auto ruleName = rule.at("rule").get<string>();

        if (ruleName == "global-message")
        {
            GlobalMessage *ruleIndex = globalMessageRule(rule);
            parallelFor->addRule(ruleIndex);
        }
        // else if (ruleName == "foreach")
        // {
        //     forEachRule(rule, forEach);
        // }
        // else if (ruleName == "parallelfor")
        // {
        //     ruleIndex = parallelForRule(rule);
        // }
        else if (ruleName == "discard")
        {
            DiscardRule *ruleIndex = discardRule(rule);
            parallelFor->addRule(ruleIndex);
        }
        else if (ruleName == "when")
        {
            WhenRule *when = whenRule(rule);
            parallelFor->addRule(when);
        }
        else if (ruleName == "input-choice")
        {
            InputChoiceRule *ruleIndex = inputChoiceRule(rule);
            parallelFor->addRule(ruleIndex);
        }
    }
    return parallelFor;
}

// Note: we cannot treat this recursive function that
// loops through all rules the same as rule=="foreach"
// "foreach" class will need to receive list + element
// and apply some rules specifically to that
ForEachRule *forEachRule(json element)
{
    ForEachRule *forEach = new ForEachRule(element.at("list").get<string>(), element.at("element").get<string>());
    json rules = element["rules"];
    for (const json rule : rules)
    {
        auto ruleName = rule.at("rule").get<string>();

        if (ruleName == "global-message")
        {
            GlobalMessage *ruleIndex = globalMessageRule(rule);
            forEach->addRule(ruleIndex);
        }
        else if (ruleName == "parallelfor")
        {
            ParallelFor *ruleIndex = parallelForRule(rule);
            forEach->addRule(ruleIndex);
        }
        else if (ruleName == "discard")
        {
            DiscardRule *ruleIndex = discardRule(rule);
            forEach->addRule(ruleIndex);
        }
        else if (ruleName == "when")
        {
            WhenRule *when = whenRule(rule);
            forEach->addRule(when);
        }
        else if (ruleName == "foreach")
        {
            ForEachRule *ruleIndex = forEachRule(rule);
            forEach->addRule(ruleIndex);
        }
        else if (ruleName == "input-choice")
        {
            InputChoiceRule *ruleIndex = inputChoiceRule(rule);
            forEach->addRule(ruleIndex);
        }
    }
    //forEach->print();
    return forEach;
}

int main()
{

    string filePath = "rockPaperScissors.json";
    ifstream ifs(filePath, std::ifstream::binary);
    if (ifs.fail())
    {
        throw std::runtime_error("Cannot open Json file");
    }

    json j = json::parse(ifs);

    //config
    // json config = j["configuration"];
    // Configuration configuration = Configuration(config["name"], config["player count"]["min"],
    //                                             config["player count"]["max"], config["audience"], config["setup"]["Rounds"]);
    // configuration.printConfiguration();

    // //constants
    // json constantsArr = j["constants"]["weapons"];
    // Constants constant;
    // for (const auto &element : constantsArr){
    //     auto name = element.at("name").get<string>();
    //     auto beats = element.at("beats").get<string>();
    //     Weapon temp(name, beats);
    //     constant.addWeapon(temp);
    // }
    // constant.print();

    // //variable
    // json variable = j["variables"]["winners"];
    // Variables var;
    // for (const auto &element : variable){
    //     string winner = element.get<string>();
    //     var.addWinner(winner);
    // }
    // var.print();
    // cout << "\n\n" <<endl;

    // Loop through the rules!
    json rules = j["rules"];
    vector<Rule *> allRule;

    int i = 0;
    for (const json element : rules)
    {
        //cout << i++ << endl;
        auto rulesName = element.at("rule").get<string>();
        //cout << rulesName << endl;
        if (rulesName == "foreach")
        {
            ForEachRule *ruleIndex = forEachRule(element);
            allRule.push_back(ruleIndex);
        }
        
        else if (rulesName == "scores")
        {
            ScoreRule *ruleIndex = scoreRule(element);
            allRule.push_back(ruleIndex);
        }
    }
    for (int i = 0 ; i < allRule.size() ; i++)
    {
        allRule[i] ->print();
    }
}
