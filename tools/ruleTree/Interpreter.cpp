#include "State.h"

using namespace std;

namespace Interpreter {

  vector<Player> InterpretListOfPlayers(string input, State state){
    vector<Player> players_list;
    vector<string> tokens = splitString(input);

    if(tokens[0]=="players"){
      // get list of players
      vector<Player> players_list = state.getPlayers();
      // convert to vector
    }
    return players_list;
  }

}
