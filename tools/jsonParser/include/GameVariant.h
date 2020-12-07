#ifndef GAME_VARIANT_H
#define GAME_VARIANT_H

#include <boost/variant.hpp>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

using GameVariant = boost::variant<unordered_map<string,string>,
                      int,
                      double,
                      bool,
                      string,
                      vector<unordered_map<string,string>>>;

// check type
enum class VARIATION { INTEGER, STRING, DOUBLE, BOOL, MAP, VECTOR, UNKNOWN };
class check_type
  : public boost::static_visitor<VARIATION> {
    public:
      VARIATION operator()(int& op) const {return VARIATION::INTEGER;}
      VARIATION operator()(double& op) const {return VARIATION::DOUBLE;}
      VARIATION operator()(bool& op) const {return VARIATION::BOOL;}
      VARIATION operator()(string& op) const {return VARIATION::STRING;}
      VARIATION operator()(unordered_map<string,string>& op) const {return VARIATION::MAP;}
      VARIATION operator()(vector<unordered_map<string,string>>& op) const {return VARIATION::VECTOR;}

      template<typename T>
      VARIATION operator()(T op) const { return VARIATION::UNKNOWN; }
};


// print function visitor for GameVariant
class printVariant
  : public boost::static_visitor<> {
    public:
      template <typename T>
      void operator()(T& op) const {
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
      template<typename T>
      string operator()(T& op) const {return to_string(op);}
      string operator()(string& op) const {return op;}
      string operator()(unordered_map<string,string>& op) const {return "";}
      string operator()(vector<unordered_map<string,string>>& op) const {return "";}
};

#endif
