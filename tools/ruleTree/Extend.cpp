#include "Extend.h"

<<<<<<< HEAD:tools/gamePlay/ruleClasses/Extend.cpp
ExtendRule::ExtendRule(string list, string target): list(list), target(target)
{
=======
ExtendRule::ExtendRule(string list, string target): list(list), target(target) {
>>>>>>> 155bab0fc2b1962c7f4c78b8e451010233c4bb67:tools/ruleTree/Extend.cpp
  // given a list, extend it with another list or variable
}

void ExtendRule::execute(State& gameState)
{

}

void ExtendRule::print()
{
  cout << "Extend Rule:" << endl;
  cout << "    list == " << list << endl;
  cout << "    target == " << target << endl;

}
<<<<<<< HEAD:tools/gamePlay/ruleClasses/Extend.cpp
=======

void ExtendRule::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

>>>>>>> 155bab0fc2b1962c7f4c78b8e451010233c4bb67:tools/ruleTree/Extend.cpp
