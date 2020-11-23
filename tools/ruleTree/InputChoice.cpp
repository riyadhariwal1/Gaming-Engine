#include "InputChoice.h"
#include "MessageParser.h"
InputChoiceRule::InputChoiceRule(string player, string prompt, string choices, string result)
{
  // send promp to a player with list of choices and
  // save choice in given variable "result"
  this->prompt = prompt;
  this->to = to;
  this->choices = choices;
  this->result = result;

}
void InputChoiceRule::execute(State& gameState)
{
  //TODO: Retrive infor from State
  Player toPlayer = gameState.getPlayers()[0];
  //choiceList = gameState.getVariables(choices);
  MessageParser msgParser(prompt, gameState);
  completePrompt = msgParser.getCompleteString();
}
void InputChoiceRule::print()
{
  cout << "InputChoice: " << endl;
  cout << "    to ==" << to << endl;
  cout << "    prompt ==" << prompt << endl;
  cout << "    choices ==" << choices << endl;
  cout << "    result ==" << result << endl;
  cout << "    timeout ==" << timeout << endl;

}

void InputChoiceRule::accept(AstVisitor& visitor, State& gameState) {
    visitor.visit(*this, gameState );
}

Player InputChoiceRule::getPlayer(){
  return toPlayer;
}

vector<GameVariant> InputChoiceRule::getChoiceList() {
  return choiceList;
}
std::string InputChoiceRule::getCompletePrompt(){
  return completePrompt;
}
int InputChoiceRule::getTimeOut(){
  return std::stof(timeout);
}
std::string InputChoiceRule::getResult(){
  return result;
}