#include "Interpreter.h"
#include <boost/algorithm/string.hpp>

using namespace std;

/*
  NOTES:
    - VARIATION is a enum in GameVariant.h that helps check type of the variants
    - we need separate functions for playerLists and otherLists (weapons)
    - checking condition is a function on its' own
    - when we have something like weapons.name, we must be working with either
    a vector or a map. "name" is a key for weapons.
    Or for winners.size, "size" is an attribute of winners.
*/

// HELPER functions -----------------------------------------------------------
namespace EVALUATOR {
  /*
    returning specifically either players or winners list
  */
  vector<Player> InterpretPlayers(string& input, State& state){
    vector<Player> players_list;
    vector<string> tokens = splitString(input, '.');

    if(tokens[0]=="players"){
      players_list = state.getPlayers();
    }
    else if(tokens[0]=="winners"){
      players_list = state.getWinners();
    }
    return players_list;
  }

  /*
    Interpret strings which only evaluate bbetween curly brackets
  */
  string InterpretString(string& msg, Element& element, State& state){

    string result="";

    std::size_t start = msg.find('{');
    std::size_t end = msg.find('}');

    string stringToExtract = msg.substr(start + 1, end - start - 1);
    vector<string> tokens = splitString(stringToExtract, '.');

    if(tokens[0]=="player" || tokens[0]=="winner"){

      Player current_player = element.getPlayer();
      result = current_player.getWithKey(tokens[1]);

    } else if ((tokens[0]=="players" || tokens[0]=="winners") &&
                tokens.size() > 2) {

        if(tokens[1]=="elements"){
          result="";
          vector<Player> list = InterpretPlayers(tokens[0], state);
          for(auto player : list){
            string token_value_at_index = player.getWithKey(tokens[2]);
            token_value_at_index+=" ";
            result+= token_value_at_index;
          }
        }
    }
    else{

      result = element.getValue();
    }
    string var = "{" + stringToExtract + "}";
    boost::replace_all(msg, var, result);

    return msg;
  }


  /*
    Interpret other strings
  */
  string InterpretString(string& msg, State& state){

    string result=msg;

    vector<string> tokens = splitString(msg, '.');
    string first_key = tokens[0];

    // players vectors
    if((tokens[0]=="players" || tokens[0]=="winners")){

      vector<Player> players = InterpretPlayers(tokens[0], state);
      if(tokens[1]=="size"){
        result = to_string(players.size());
      }

    }
    // other variables
    else {
      GameVariant first_variable_variant = state.getFromState(first_key);

      if(boost::apply_visitor( gameVariant_to_string(), first_variable_variant)!=""){
        result = boost::apply_visitor( gameVariant_to_string(), first_variable_variant);
      }

      if(tokens.size() > 1){

        // must be vector or a map to have a second key
        string second_key = tokens[1];
        VARIATION variable_type = boost::apply_visitor( check_type(), first_variable_variant);

        if(variable_type==VARIATION::MAP){
          unordered_map<string,string> map = boost::get<unordered_map<string,string>>( first_variable_variant );
          result = map.at(second_key);
        }
        else if(variable_type==VARIATION::VECTOR){
          result="";
          vector<unordered_map<string,string>>
          vec = boost::get<vector<unordered_map<string,string>>>( first_variable_variant );

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


  /*
    Extract function out of rawInput
  */
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

  bool ApplyFunction(State& state, string function,
                     vector<unordered_map<string,string>> list,vector<string> tokens, string element){
    return false;
  }

  bool ApplyFunction(State& state, string function,
                     vector<Player> players,vector<string> tokens, string element){

      string element_key = tokens[2];
      if(function.find("contains") != string::npos){
        for(auto& player : players){
          if(player.getWithKey(element_key)==element){
            return true;
          }
        }
      }
    return false;
  }

}

// ----------------------------------------------------------------------------

/*
  Sometimes we need to use elements: {Rounds} or (weapons.name),
  and sometimes we only need state: weapons.name
  We try to intrepret either type generically and return a string
  If we need multiple values, like for choices, we return one string with
  the multiple choices
*/
string
INTERPRETER::InterpretString(string& msg, Element& element, State& state){
  string result="";

  std::size_t start = msg.find('{');
  std::size_t end = msg.find('}');

  bool requires_element = (start != std::string::npos)
                              && (end != std::string::npos)
                              && (start < end);

  if (requires_element){

    result = EVALUATOR::InterpretString(msg, element, state);
  }
  else {
    result = EVALUATOR::InterpretString(msg, state);
  }
  return result;
}

/*
  Use Shunting Yard algorithm
  ideally we should be able to handle multiple types of conditions:
  1. Equality types:  == , > , < , <=, >= ( 2 arguments)
  - Functions on lists: contains .. (1 vector argument)
  - equality AND functions in same condition
*/
bool
INTERPRETER::InterpretCondition(string& input, Element& element, State& state){
  bool condition=false;

  size_t find_equal_sign = input.find("==");
  if(find_equal_sign!=string::npos){
    // condition is an equality check
    vector<string> arguments = splitString(input, '=');
    for(auto& token : arguments){
      boost::erase_all(token, "=");
      boost::erase_all(token, " ");
    }
    cout << arguments[0] << " and " << arguments.back() << endl;
    string first = EVALUATOR::InterpretString(arguments[0], state);
    string second = EVALUATOR::InterpretString(arguments.back(), state);
    cout << first << " and " << second << endl;

    if(first.compare(second)==0){
      condition=!condition;
      return condition;
    }
  }
  else {
    // condition is a function
    vector<string> tokens = EVALUATOR::SplitOutFunction(input);
    string function = tokens.back();
    tokens.pop_back(); // remove function from tokens

    if(tokens[0].at(0)=='!'){ // handle not
      condition = !condition;
      tokens[0] = tokens[0].substr(1, tokens[0].length());
    }

    if(tokens[0]=="players" || tokens[0]=="winners"){

      vector<Player> list = EVALUATOR::InterpretPlayers(tokens[0], state);
      if(tokens.size() > 2 && list.size() > 0){
        condition = EVALUATOR::ApplyFunction(state, function, list, tokens, element.getValue());
      }
    }
  }
    return condition;
}

// bool
// INTERPRETER::InterpretCondition(string& input, Element& element, State& state){
//   bool condition=false;
//
//   condition = TRANSLATOR::evaluateCondition(input, element, state);
//
//   return condition;
// }
