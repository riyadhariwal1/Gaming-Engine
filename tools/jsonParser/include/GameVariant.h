#ifndef GAME_VARIANT_H
#define GAME_VARIANT_H

#include <boost/variant.hpp>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <type_traits>

using namespace std;

// GAME_VARIANT
//typedef boost::variant<unordered_map<string,string>, int, double, bool, string> ListType;
typedef boost::variant<unordered_map<string,string>,
                      int,
                      double,
                      bool,
                      string,
                      vector<unordered_map<string,string>>> GameVariant;

// visitor classes for gameVariant

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

#endif
