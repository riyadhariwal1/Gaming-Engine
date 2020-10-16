#include "GlobalMessage.h"
#include <iostream>
using namespace std;

GlobalMessage::GlobalMessage(string& value) : value(value){
}
   
void GlobalMessage::execute(GameState&){
    cout<<value<<endl;
}
