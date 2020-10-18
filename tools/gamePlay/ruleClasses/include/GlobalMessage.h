#ifndef GLOBAL_MESSAGE_RULE_H
#define GLOBAL_MESSAGE_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>

class GlobalMessage {
    public:
        explicit GlobalMessage(std::string& value);
        void execute();
    private:
        std::string& value;

};
#endif
