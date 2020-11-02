#include "State.h"

State::State(vector<Player> playerList, Configuration configuration, Constants constants, Variables variables)
    : playerList(playerList), configuration(configuration), constants(constants), variables(variables)
{
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
