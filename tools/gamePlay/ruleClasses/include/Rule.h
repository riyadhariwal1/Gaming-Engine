#ifndef RULE_H
#define RULE_H
#include<string>
 #include "GameState.h"

class Rule {
    public:
        Rule();
        virtual void execute(string&);
};
#endif
