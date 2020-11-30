#ifndef SOCIAL_GAMING_LOADER_H
#define SOCIAL_GAMING_LOADER_H

#include <iostream>
#include <nlohmann/json.hpp>
#include "Configuration.h"
#include "Constants.h"
#include "Variables.h"
#include <fstream>
#include <sstream>
#include "GlobalMessage.h"
#include "Extend.h"
#include "When.h"
#include "Discard.h"
#include "ForEach.h"
#include "ParallelFor.h"
#include "Player.h"
#include "InputChoice.h"
#include "Scores.h"
#include "Add.h"

using namespace std;
using json = nlohmann::json;

class Loader {
public:

    ForEachRule* forEachRule(json element);
    GlobalMessage * globalMessageRule (json rule);
    void addRule (json rule);
    InputChoiceRule * inputChoiceRule(json rule);
    DiscardRule * discardRule (json rule);
    WhenRule * whenRule (json rule);
    ParallelFor * parallelForRule (json rule);
    ExtendRule* extendRule (json rule);
    ScoreRule * scoreRule(json rule);


};

#endif //SOCIAL_GAMING_LOADER_H
