#include "Loader.h"

using namespace std;
using json = nlohmann::json;

/* DECLARATIONS */
//ForEachRule* forEachRule(json element);

/* -- */
GlobalMessage* Loader::globalMessageRule(json rule)
{
    cout << "Global Message" << endl;
    GlobalMessage *globalMessage = new GlobalMessage(rule.at("value").get<string>());

    return globalMessage;
}

void Loader::addRule(json rule)
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

InputChoiceRule *Loader::inputChoiceRule(json rule)
{
    //cout << "Im in input" << endl;

    InputChoiceRule *input = new InputChoiceRule(rule.at("prompt").get<string>(),
                                                 rule.at("choices").get<string>(),
                                                 rule.at("result").get<string>(),
                                                 rule.at("to").get<string>());

    return input;
}
DiscardRule *Loader::discardRule(json rule)
{
    //cout << "Im in discard" << endl;
    DiscardRule *discard = new DiscardRule(rule.at("from").get<string>(), rule.at("count").get<string>());

    return discard;
}
ExtendRule* Loader::extendRule (json rule)
{
    //cout << "Im in extend" << endl;
    ExtendRule* extend = new ExtendRule(rule.at("list").get<string>(), rule.at("target").get<string>());
    return extend;
}

WhenRule *Loader::whenRule(json rule)
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
ScoreRule * Loader::scoreRule(json rule)
{
    ScoreRule* scoreRule = new ScoreRule (rule.at("score").get<string>(), rule.at("ascending").get<bool>());
    return scoreRule;

}
ParallelFor *Loader::parallelForRule(json rule)
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
ForEachRule *Loader::forEachRule(json element)
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
