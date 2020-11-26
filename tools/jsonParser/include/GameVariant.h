#ifndef GAME_VARIANT_H
#define GAME_VARIANT_H

#include <boost/variant.hpp>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// GAME_VARIANT
//typedef boost::variant<unordered_map<string,string>, int, double, bool, string> ListType;
typedef boost::variant<unordered_map<string,string>,
                      int,
                      double,
                      bool,
                      string,
                      vector<unordered_map<string,string>>> GameVariant;


// check type
enum class VARIATION { INTEGER, STRING, DOUBLE, BOOL, MAP, VECTOR };
class check_type
  : public boost::static_visitor<VARIATION> {
    public:
      VARIATION operator()(int& op) const {return VARIATION::INTEGER;}
      VARIATION operator()(double& op) const {return VARIATION::DOUBLE;}
      VARIATION operator()(bool& op) const {return VARIATION::BOOL;}
      VARIATION operator()(string& op) const {return VARIATION::STRING;}
      // no string conversion for these
      VARIATION operator()(unordered_map<string,string>& op) const {return VARIATION::MAP;}
      VARIATION operator()(vector<unordered_map<string,string>>& op) const {return VARIATION::VECTOR;}
};


// print function visitor for GameVariant
class printVariant
  : public boost::static_visitor<> {
    public:
      void operator()(int& op) const {
        cout << " : " << op << endl;
      }
      void operator()(double& op) const {
        cout << " : " << op << endl;
      }
      void operator()(bool& op) const {
        cout << " : " << op << endl;
      }
      void operator()(string& op) const {
        cout << " : " << op << endl;
      }
      void operator()(unordered_map<string,string>& op) const {
        cout << endl;
        for ( auto itrr : op){
          cout << "       " ;
          cout << itrr.first << " : " << itrr.second << endl;
        }
      }
      void operator()(vector<unordered_map<string,string>>& op) const {
        cout << endl;
        for( auto index : op){
          for ( auto itrr : index){
            cout << "       ";
            cout << itrr.first << " : " << itrr.second << endl;
          }
        }
      }
};

// get variant as string
class gameVariant_to_string
  : public boost::static_visitor<string> {
    public:
      string operator()(int& op) const {return to_string(op);}
      string operator()(double& op) const {return to_string(op);}
      string operator()(bool& op) const {return to_string(op);}
      string operator()(string& op) const {return op;}
      // no string conversion for these
      string operator()(unordered_map<string,string>& op) const {return "";}
      string operator()(vector<unordered_map<string,string>>& op) const {return "";}
};



//-------------------------------------------------------------------------------------
//JUST FOR TEST PURPOSE
// visitor classes for gameVariant
// get variant as original type
struct GameVariant_Types {
  int type_int= -1;
  double type_double= -1;
  string type_string = "warning: no string value";
  bool type_bool=0;
  unordered_map<string, string> type_map{};
  vector<unordered_map<string,string>> type_vector{};
};

// mostly just for debugging
class conversion
  : public boost::static_visitor<GameVariant_Types> {
    public:
      GameVariant_Types operator()(int& op) const {
        GameVariant_Types convert;
        convert.type_int=op;
        return convert;
      }
      GameVariant_Types operator()(double& op) const {
        GameVariant_Types convert;
        convert.type_double=op;
        return convert;
      }
      GameVariant_Types operator()(bool& op) const {
        GameVariant_Types convert;
        convert.type_bool=op;
        return convert;
      }
      GameVariant_Types operator()(string& op) const {
        GameVariant_Types convert;
        convert.type_string=op;
        return convert;
      }
      GameVariant_Types operator()(unordered_map<string,string>& op) const {
        GameVariant_Types convert;
        convert.type_map.insert(op.begin(), op.end());
        return convert;
      }
      GameVariant_Types operator()(vector<unordered_map<string,string>>& op) const {
        GameVariant_Types convert;
        unordered_map<string,string> temp_map;
        for( auto index : op){
          temp_map.insert(index.begin(), index.end());
          convert.type_vector.push_back(temp_map);
          temp_map.clear();
        }
        return convert;
      }
};

#endif
