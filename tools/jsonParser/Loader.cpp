#include "Loader.h"

void Loader::globalMessageRule (json rule)
{
    cout << " im in global" << endl;
    cout << rule.dump() << endl;

    string ruleTest = rule["value"].dump();
    GlobalMessage gm(ruleTest);
    gm.execute();

    cout << "\n";

}

void Loader::addRule (json rule)
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

void Loader::inputChoiceRule(json rule)
{
    cout << " im in input" << endl;

}

//Discard
//{ "rule": "discard",
//"from": << variable name of a list to discard from >>,
//"count": << number of elements to discard >>
//}
void Loader::discardRule (json rule) {
    cout << " im in discard" << endl;
}

void Loader::whenRule (json rule)
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
// void Loader::parallelForRule (json rule)
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
void Loader::forEachRule(json element)
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



