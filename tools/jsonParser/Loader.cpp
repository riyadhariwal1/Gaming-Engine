#include "Loader.h"

using namespace std;
using json = nlohmann::json;

/* DECLARATIONS */
//ForEachRule* forEachRule(json element);

/* -- */
std::unique_ptr<GlobalMessage>
Loader::globalMessageRule(json rule) {
    return std::make_unique<GlobalMessage>(rule.at("value").get<string>());
}

//TODO: this
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

std::unique_ptr<InputChoiceRule>
Loader::inputChoiceRule(json rule) {
    return std::make_unique<InputChoiceRule>(rule.at("prompt").get<string>(),
                                            rule.at("choices").get<string>(),
                                            rule.at("result").get<string>(),
                                            rule.at("to").get<string>(),
                                            rule.at("timeout").get<int>());
}

std::unique_ptr<DiscardRule>
Loader::discardRule(json rule) {
    return std::make_unique<DiscardRule>(rule.at("from").get<string>(), rule.at("count").get<string>());
}

std::unique_ptr<ExtendRule>
Loader::extendRule (json rule) {
    return std::make_unique<ExtendRule>(rule.at("list").get<string>(), rule.at("target").get<string>());
}

std::unique_ptr<WhenRule>
Loader::whenRule(json rule) {

    json conditions = rule["cases"];

    std::unique_ptr<WhenRule> whenRule = std::make_unique<WhenRule>();
    for (const json ele : conditions) {
        string check = ele["condition"].dump();
        std::unique_ptr<Case> condition = std::make_unique<Case>(check);

        json ruleList = ele["rules"];

        for (const json element : ruleList) {
            auto ruleName = element.at("rule").get<string>();
            if (ruleName == "extend") {
                std::unique_ptr<ExtendRule> ruleIndex = std::make_unique<ExtendRule>(element);
                condition->addRule(ruleIndex);
            }
            else if (ruleName == "global-message") {
                std::unique_ptr<GlobalMessage> ruleIndex = std::make_unique<GlobalMessage>(element);
                condition->addRule(ruleIndex);
            }
            else if (ruleName == "foreach") {
                std::unique_ptr<ForEachRule> ruleIndex = std::make_unique<ForEachRule>(element);
                condition->addRule(ruleIndex);
            }
        }
        cout << endl;
        whenRule->addCase(std::move(condition));
        //parse the given condition
        //if condition is true: extract element["rules"]
    }
    //whenRule->print();
    return whenRule;
}

std::unique_ptr<ScoreRule>
Loader::scoreRule(json rule) {
    return std::make_unique<ScoreRule>(rule.at("score").get<string>(), rule.at("ascending").get<bool>());
}

std::unique_ptr<ParallelFor>
Loader::parallelForRule(json rule) {
    //cout << " im in parrallel" << endl;
    std::unique_ptr<ParallelFor> parallelFor = std::make_unique<ParallelFor>(rule.at("list").get<string>(),
                                                                             rule.at("element").get<string>());
    json rules = rule["rules"];
    for (const json rule : rules) {
        auto ruleName = rule.at("rule").get<string>();

        if (ruleName == "global-message") {
            std::unique_ptr<GlobalMessage> ruleIndex = std::make_unique<GlobalMessage>(rule);
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
        else if (ruleName == "discard") {
            std::unique_ptr<DiscardRule> ruleIndex = std::make_unique<DiscardRule>(rule);
            parallelFor->addRule(ruleIndex);
        }
        else if (ruleName == "when") {
            std::unique_ptr<WhenRule> ruleIndex = std::make_unique<WhenRule>(rule);
            parallelFor->addRule(when);
        }
        else if (ruleName == "input-choice") {
            std::unique_ptr<InputChoiceRule> ruleIndex = std::make_unique<InputChoiceRule>(rule);
            parallelFor->addRule(ruleIndex);
        }
    }
    return parallelFor;
}

// Note: we cannot treat this recursive function that
// loops through all rules the same as rule=="foreach"
// "foreach" class will need to receive list + element
// and apply some rules specifically to that
std::unique_ptr<ForEachRule>
Loader::forEachRule(json element) {

    std::unique_ptr<ForEachRule> forEach = std::make_unique<ForEachRule>(element.at("list").get<string>(),
                                                                         element.at("element").get<string>());
    json rules = element["rules"];
    for (const json rule : rules) {
        auto ruleName = rule.at("rule").get<string>();

        if (ruleName == "global-message") {
            std::unique_ptr<GlobalMessage> ruleIndex = std::make_unique<GlobalMessage>(rule);
            forEach->addRule(ruleIndex);
        }
        else if (ruleName == "parallelfor") {
            std::unique_ptr<ParallelFor> ruleIndex = std::make_unique<ParallelFor>(rule);
            forEach->addRule(ruleIndex);
        }
        else if (ruleName == "discard") {
            std::unique_ptr<DiscardRule> ruleIndex = std::make_unique<DiscardRule>(rule);
            forEach->addRule(ruleIndex);
        }
        else if (ruleName == "when") {
            std::unique_ptr<WhenRule> ruleIndex = std::make_unique<WhenRule>(rule);
            forEach->addRule(when);
        }
        else if (ruleName == "foreach") {
            std::unique_ptr<ForEachRule> ruleIndex = std::make_unique<ForEachRule>(rule);
            forEach->addRule(ruleIndex);
        }
        else if (ruleName == "input-choice") {
            std::unique_ptr<InputChoiceRule> ruleIndex = std::make_unique<InputChoiceRule>(rule);
            forEach->addRule(ruleIndex);
        }
    }
    //forEach->print();
    return forEach;
}
