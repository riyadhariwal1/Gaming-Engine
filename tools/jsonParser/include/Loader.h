#ifndef SOCIAL_GAMING_LOADER_H
#define SOCIAL_GAMING_LOADER_H

#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Constants.h"
#include "Variables.h"
#include <fstream>
#include <sstream>
#include "Game.h"
#include "GlobalMessage.h"
#include "Player.h"
#include "Add.h"

using namespace std;
using json = nlohmann::json;

class Loader {
public:

    void forEachRule(json element);
    void globalMessageRule (json rule);
    void addRule (json rule);
    void inputChoiceRule(json rule);
    void discardRule (json rule);
    void whenRule (json rule);
    //void parallelForRule (json rule);

};

#endif //SOCIAL_GAMING_LOADER_H
