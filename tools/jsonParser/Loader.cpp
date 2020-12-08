#include "Loader.h"
#include "Element.h"

using namespace std;
using json = nlohmann::json;

std::unique_ptr<GlobalMessage>
Loader::globalMessageRule(json rule) {
    return std::make_unique<GlobalMessage>(rule.at("value").get<string>());
}

std::unique_ptr<AddRule>
Loader::addRule(json rule) {
    return std::make_unique<AddRule>(rule.at("to").get<string>(),
                                     rule.at("value").get<int>());
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
                std::unique_ptr<ExtendRule> ruleIndex = extendRule(element);
                condition->addRule(std::move(ruleIndex));
            }
            else if (ruleName == "global-message") {
                std::unique_ptr<GlobalMessage> ruleIndex = globalMessageRule(element);
                condition->addRule(std::move(ruleIndex));
            }
            else if (ruleName == "foreach") {
                std::unique_ptr<ForEachRule> ruleIndex = forEachRule(element);
                condition->addRule(std::move(ruleIndex));
            }
        }
        cout << endl;
        whenRule->addCase(std::move(condition));
    }
    return whenRule;
}

std::unique_ptr<ScoreRule>
Loader::scoreRule(json rule) {
    return std::make_unique<ScoreRule>(rule.at("score").get<string>(), rule.at("ascending").get<bool>());
}

std::unique_ptr<ParallelFor>
Loader::parallelForRule(json rule) {
    std::unique_ptr<ParallelFor> parallelFor = std::make_unique<ParallelFor>(rule.at("list").get<string>(),
                                                                             rule.at("element").get<string>());
    json rules = rule["rules"];
    for (const json rule : rules) {
        auto ruleName = rule.at("rule").get<string>();

        if (ruleName == "global-message") {
            std::unique_ptr<GlobalMessage> ruleIndex = globalMessageRule(rule);
            parallelFor->addRule(std::move(ruleIndex));
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
            std::unique_ptr<DiscardRule> ruleIndex = discardRule(rule);
            parallelFor->addRule(std::move(ruleIndex));
        }
        else if (ruleName == "when") {
            std::unique_ptr<WhenRule> ruleIndex = whenRule(rule);
            parallelFor->addRule(std::move(ruleIndex));
        }
        else if (ruleName == "input-choice") {
            std::unique_ptr<InputChoiceRule> ruleIndex = inputChoiceRule(rule);
            parallelFor->addRule(std::move(ruleIndex));
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
            std::unique_ptr<GlobalMessage> ruleIndex = globalMessageRule(rule);
            forEach->addRule(std::move(ruleIndex));
        }
        else if (ruleName == "parallelfor") {
            std::unique_ptr<ParallelFor> ruleIndex = parallelForRule(rule);
            forEach->addRule(std::move(ruleIndex));
        }
        else if (ruleName == "discard") {
            std::unique_ptr<DiscardRule> ruleIndex = discardRule(rule);
            forEach->addRule(std::move(ruleIndex));
        }
        else if (ruleName == "when") {
            std::unique_ptr<WhenRule> ruleIndex = whenRule(rule);
            forEach->addRule(std::move(ruleIndex));
        }
        else if (ruleName == "foreach") {
            std::unique_ptr<ForEachRule> ruleIndex = forEachRule(rule);
            forEach->addRule(std::move(ruleIndex));
        }
        else if (ruleName == "input-choice") {
            std::unique_ptr<InputChoiceRule> ruleIndex = inputChoiceRule(rule);
            forEach->addRule(std::move(ruleIndex));
        }
        else if (ruleName == "add") {
            std::unique_ptr<AddRule> ruleIndex = addRule(rule);
            forEach->addRule(std::move(ruleIndex));
        }
    }
    //forEach->print();
    return forEach;
}
