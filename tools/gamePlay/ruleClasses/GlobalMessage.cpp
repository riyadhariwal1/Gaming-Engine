#include "GlobalMessage.h"
#include <iostream>


// template Rule

GlobalMessage::GlobalMessage(string& value) : value(value){
}

void GlobalMessage::execute(){
  // replace in string
  // Example:  "Winners: {winners.elements.name}"
    cout<<value<<endl;
}
