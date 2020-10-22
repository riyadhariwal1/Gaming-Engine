#ifndef GLOBAL_MESSAGE_RULE_H
#define GLOBAL_MESSAGE_RULE_H
#include "Rule.h"
#include <string>

class GlobalMessage : public Rule{
    public:
        GlobalMessage(string value);
        void execute(GameState&) override ;
        void print() override;
    private:
        string value;

};
#endif
