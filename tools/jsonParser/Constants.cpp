#include "Constants.h"

Constants::Constants(unordered_map<string,GameVariant> constantsMap)
 : constantsMap(constantsMap) {};

void Constants::print(){
  cout << "Constants: \n";
  for ( auto itrr : this->constantsMap)
  {
    cout << "   " << itrr.first;
    switch(itrr.second.which()){
      case 0:
        cout << "\n";
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
