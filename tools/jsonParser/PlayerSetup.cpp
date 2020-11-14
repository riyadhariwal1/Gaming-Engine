//
// Created by SUNAINA PAUDEL
//
#include "PlayerSetup.h"


PerPlayer::PerPlayer(unordered_map<string,GameVariant> playerMap)
 : playerMap(playerMap) {};

void PerPlayer::print(){
  cout << "Per_Player: \n";
  for ( auto itrr : this->playerMap)
  {
    cout << "   " << itrr.first;
    switch(itrr.second.which()){
      case 0:
        cout << endl;
        for (auto i : boost::get<unordered_map<string,string>>(itrr.second)){
          cout << "   "<< i.first << ":" << i.second << endl;
        }
        break;
      case 1:
        cout << ": " << boost::get<int>(itrr.second) << endl;
        break;
      case 2:
        cout << ": " << boost::get<double>(itrr.second) << endl;
        break;
      case 3:
        cout << ": " << boost::get<bool>(itrr.second) << endl;
        break;
      case 4:
        cout << ": " << boost::get<string>(itrr.second) << endl;
        break;
      //List
      case 5:
        cout << "\n";
        // a cheat for now
        // needs to be vector<ListType> - will handle with visitor
        for (auto vec : boost::get<vector<unordered_map<string,string>>>(itrr.second)){
          for( auto val : vec){
              cout << "     "<< val.first << ":" << val.second << endl;
          }
          cout << endl;
        }
      default:
      // setup does not have lists
        cout << "" << endl;
    }

  }
}

PerAudience::PerAudience(unordered_map<string,GameVariant> audienceMap)
 : audienceMap(audienceMap) {};

void PerAudience::print(){
  cout << "Per_Audience: \n";
  for ( auto itrr : this->audienceMap)
  {
    cout << "   " << itrr.first;
    switch(itrr.second.which()){
      case 0:
        cout << endl;
        for (auto i : boost::get<unordered_map<string,string>>(itrr.second)){
          cout << "   "<< i.first << ":" << i.second << endl;
        }
        break;
      case 1:
        cout << ": " << boost::get<int>(itrr.second) << endl;
        break;
      case 2:
        cout << ": " << boost::get<double>(itrr.second) << endl;
        break;
      case 3:
        cout << ": " << boost::get<bool>(itrr.second) << endl;
        break;
      case 4:
        cout << ": " << boost::get<string>(itrr.second) << endl;
        break;
      //List
      case 5:
        cout << "\n";
        // a cheat for now
        // needs to be vector<ListType> - will handle with visitor
        for (auto vec : boost::get<vector<unordered_map<string,string>>>(itrr.second)){
          for( auto val : vec){
              cout << "     "<< val.first << ":" << val.second << endl;
          }
          cout << endl;
        }
      default:
      // setup does not have lists
        cout << "" << endl;
    }

  }
}
