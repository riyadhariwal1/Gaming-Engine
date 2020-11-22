#include "Extend.h"
#include <iostream>

ExtendRule::ExtendRule(string list, string target): list(list), target(target)
{}


void ExtendRule::execute(State& gameState) {
//TODO: function that finds list based on name: ex. getListByName(target);
    vector<Player> targetList = gameState.getWinners();
//TODO: function that parses list. format of the string is: nameOfList.whatYouWantFromIt.function(condition)
    vector<Player> list;
    targetList.insert(targetList.end(), list.begin(), list.end());

}

void ExtendRule::print() {
  cout << "Extend Rule:" << endl;
  cout << "    list == " << list << endl;
  cout << "    target == " << target << endl;
}


void ExtendRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState);
}
