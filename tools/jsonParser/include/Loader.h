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

    std::unique_ptr<ForEachRule> forEachRule(json element);
    std::unique_ptr<GlobalMessage> globalMessageRule (json rule);
    void addRule (json rule);
    std::unique_ptr<InputChoiceRule> inputChoiceRule(json rule);
    std::unique_ptr<DiscardRule> discardRule (json rule);
    std::unique_ptr<WhenRule> whenRule (json rule);
    std::unique_ptr<ParallelFor> parallelForRule (json rule);
    std::unique_ptr<ExtendRule> extendRule (json rule);
    std::unique_ptr<ScoreRule> scoreRule(json rule);


};

#endif //SOCIAL_GAMING_LOADER_H
