#include "Interpreter.h"
#include <boost/algorithm/string.hpp>

using namespace std;

/*
  NOTES:
    - VARIATION is a enum in GameVariant.h that helps check type of the variants
    - we need separate functions for playerLists and otherLists (weapons)
    - condition is a function on its' own
    - when we have something like weapons.name, we must be working with either
    a vector or a map. "name" is a key of weapons.
    Or for winners.size, "size" is an attribute of winners.
    We are working with vector or maps for either
    -

*/

// HELPER functions -----------------------------------------------------------
namespace HELPER {

  // anything with {} is using element
  string InterpretString(string& msg, Element& element){

    string result=msg;

    std::size_t start = msg.find('{');
    std::size_t end = msg.find('}');
    string stringToExtract = msg.substr(start + 1, end - start - 1);

    // Tokens are the words separated by "."
    vector<string> tokens = splitString(stringToExtract, '.');

    if (start != std::string::npos && end != std::string::npos && start < end)
    {
        string get_element_as_string="";

        if(tokens[0]=="player" || tokens[0]=="winner"){
          Player current_player = element.getPlayer();
          get_element_as_string = current_player.getWithKey(tokens[1]);
          // should be able to handle player.weapon.name
          // if (tokens.size() > 2) {}
        }
        else{
          get_element_as_string = element.getValue();
        }
        string var = "{" + stringToExtract + "}";
        boost::replace_all(result, var, get_element_as_string);
    }
    return result;
  }
  string InterpretString(string& msg, State& state){

    string result="";
    vector<string> tokens = splitString(msg, '.');

    string first_key = tokens[0];

    // players vectors
    if(tokens[0]=="players" && tokens.size() > 1){
      vector<Player> players = state.getPlayers();
      if(tokens[1]=="size"){
        result = to_string(players.size());
      }
    }
    else if(tokens[0]=="winners" && tokens.size() > 1){
      vector<Player> winners = state.getWinners();
      if(tokens[1]=="size"){
        result = to_string(winners.size());
      }
    }
    // other variables
    else {
      GameVariant first_variable = state.getFromState(first_key);
      result = boost::apply_visitor( gameVariant_to_string(), first_variable);

      if(tokens.size() > 1){
        // must be vector or a map to have a second key
        string second_key = tokens[1];
        VARIATION variable_type = boost::apply_visitor( check_type(), first_variable);

        if(variable_type==VARIATION::MAP){
          unordered_map<string,string> map = boost::get<unordered_map<string,string>>( first_variable );
          result = map.at(second_key);
        }
        else if(variable_type==VARIATION::VECTOR){
          vector<unordered_map<string,string>>
          vec = boost::get<vector<unordered_map<string,string>>>( first_variable );

          for( auto vector_index : vec ){
            string token_value_at_index = vector_index.at(second_key);
            token_value_at_index += " ";
            result += token_value_at_index;

          }
        }
      }
    }

    return result;

  }
  vector<string> SplitOutFunction(string& input){
    vector<string> split_at_function_param = splitString(input, '(');
    vector<string> tokens = splitString(split_at_function_param[0], '.');

    string function = tokens.back();
    if(split_at_function_param[1].back()==')'){
      function = function + "("+ split_at_function_param[1];
    }
    tokens.pop_back();

    tokens.push_back(function);
    return tokens;
  }

  bool RunFunctionOnList(vector<Player> players, string function,string element= ""){

  }
}

// ----------------------------------------------------------------------------
// interpreter functions
vector<Player>
INTERPRETER::InterpretListOfPlayers(string& input, State& state){

  vector<Player> players_list;
  vector<string> tokens = splitString(input, '.');

  if(tokens[0]=="players"){
    vector<Player> players_list = state.getPlayers();
  }
  else if(tokens[0]=="winners"){
      vector<Player> players_list = state.getWinners();
  }
  return players_list;
}

string
INTERPRETER::InterpretString(string& msg, Element& element, State& state){
  string result="";

  std::size_t start = msg.find('{');
  std::size_t end = msg.find('}');

  // if there are curly brackets
  if (start != std::string::npos && end != std::string::npos && start < end){
    result = HELPER::InterpretString(msg, element);
  }
  else {
    result = HELPER::InterpretString(msg, state);
  }

  return result;
}

bool
INTERPRETER::InterpretCondition(string& input,Element& element, State& state){
  bool condition=false;

  size_t find_equal_sign = input.find("==");
  if(find_equal_sign!=string::npos){
    // condition is an equality check
    vector<string> arguments = splitString(input, '=');
    for(auto& token : arguments){
      cout << token << endl;
      boost::erase_all(token, "=");
      boost::erase_all(token, " ");
    }

    //evaluate arguments
    string first = HELPER::InterpretString(arguments[0], state);
    string second = HELPER::InterpretString(arguments.back(), state);
    cout << arguments[0] << " and " << arguments[1] << endl;
    cout << first << " and "<< second << endl;
    if(first.compare(second)==0){
      condition=true;
      return condition;
    }
  }
  else {
    // condition is a function
    vector<string> tokens = HELPER::SplitOutFunction(input);
    string function = tokens.back();
    tokens.pop_back();

    if(tokens[0].at(0)=='!'){
      condition = !condition;
      tokens[0] = tokens[0].substr(1, tokens[0].length());
    }

    if(tokens[0]=="players" || tokens[0]=="winners"){
      vector<Player> elements = InterpretListOfPlayers(tokens[0], state);

      if(tokens.size() > 2){
        // look for specific element value, like player.elements."weapon"
        for(auto& it : elements){

        }
      }
    }
  }


    return condition;
}
