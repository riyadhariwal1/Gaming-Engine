#include "State.h"

State::State(vector<Player> playerList, Configuration configuration,
             Constants constants, Variables variables, PerPlayer perPlayer, PerAudience perAudience)
    : playerList(playerList), configuration(configuration), constants(constants), variables(variables),
    per_player(perPlayer), per_audience(perAudience){}


// void State::UpdateState_PlayerList(vector<Player> p){
//   //for each p
// }
void State::UpdateState_Config(Configuration c){
  this->configuration = c;
}
void State::UpdateState_Constants(Constants c){
  this->constants = c;
}
void State::UpdateState_Variables(Variables v){
  this->variables = v;
}
void State::UpdateState_PerPlayer(PerPlayer pp){
  this->per_player = pp;
}
void State::UpdateState_PerAudience(PerAudience pa){
  this->per_audience = pa;
}

auto State::getPlayers() {
  return playerList;
}

Configuration State::getConfiguration(){
  return configuration;
}

Constants State::getConstants(){
  return constants;
}

bool State::checkIfStateValueNeeded(string value){

  size_t open = value.find("{");
  size_t close = value.find("}") - open + 1;

  string variableToReplace = value.substr(open, close);
  value.replace(open, close, "VARIABLE");
  cout << value << endl;
  return true;
}

// string manipulation
void State::replaceWithStateValue(string input){


}


auto State::findByName(string input)
{
    auto i = 0;
    //vector<Player> result;
    //vector<Player> temp;
    vector<string> splitString;

    while (input != "")
    {

        int pos = input.find(".");
        if (pos != 0)
        {
            splitString.push_back(input.substr(0, pos - 1));
            input = input.substr(pos + 1);
        }
    }
  /*  if (splitString.size() == 1)
    {
        if (splitString.front() == "players")
        {
            //result = playerList;
        }
        else if (splitString.front() == "winners")
        {
            //result = winnerList;
        }
    }
    else
    {
        for (int i = 0; i++; i < splitString.size())
        {
            if (splitString[0] == "winners")
            {
                //temp = winnerList;
            }
        }
    }*/
    return i;
}
