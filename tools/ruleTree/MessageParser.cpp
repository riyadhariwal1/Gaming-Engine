#include "MessageParser.h"
#include <boost/algorithm/string/replace.hpp>
MessageParser::MessageParser(string msg, State &state)
{
    // Check whether variable is in msg
    //hasDecipheredVariable = false;
    originalMsg = msg;
    completeMsg = "";
    varString = "";
    varValue = "";
    std::size_t start = msg.find('{');
    std::size_t end = msg.find('}');
    if (start != std::string::npos && end != std::string::npos && start < end)
    {
        hasDecipheredVariable = true;
        varString = msg.substr(start + 1, end - start - 1);
        findVariableInState(state);
    }
    else
    {
        hasDecipheredVariable = false;
    }
    replaceVariableWithValue();
};
std::string MessageParser::getVariableString()
{
    return varString;
}
void MessageParser::findVariableInState(State &state)
{
    //ToDo: Find the value of variable in the State and let varValue = value
}
void MessageParser::replaceVariableWithValue()
{
    completeMsg = originalMsg;
    if (hasDecipheredVariable)
    {
        std::string var = "{" + varString + "}";
        boost::replace_all(completeMsg, var, varValue);
    }
}
std::string MessageParser::getCompleteString()
{
    return completeMsg;
}
bool MessageParser::containDecipheredVariable()
{
    return this->hasDecipheredVariable;
}
