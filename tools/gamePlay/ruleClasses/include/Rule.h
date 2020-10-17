#ifndef RULE_H
#define RULE_H
#include<string>
 #include "GameState.h"

class Rule {
    public:
        virtual void execute(GameState&);
};
#endif
