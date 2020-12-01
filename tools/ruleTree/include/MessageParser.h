#ifndef MESSAGE_PARSER_H
#define MESSAGE_PARSER_H

#include "State.h"
#include <optional>
class MessageParser {
    public:
    MessageParser(string,State&);
    MessageParser(string,State&, string);
    bool containDecipheredVariable();
    std::string getVariableString();
    void findVariableInState(State&);
    void replaceVariableWithValue();
    std::string getCompleteString();

    private:
    string originalMsg;
    string varString;
    string varValue;
    string completeMsg;
    string value;
    bool hasDecipheredVariable;

};
#endif