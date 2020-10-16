#ifndef GLOBAL_MESSAGE_RULE_H
#define GLOBAL_MESSAGE_RULE_H
#include "Rule.h"
#include "GameState.h"
#include<string>

class GlobalMessage : public Rule {
    public:
        explicit GlobalMessage(std::string& value);
        void execute(GameState&) override;
    private:
        std::string& value;

};
#endif