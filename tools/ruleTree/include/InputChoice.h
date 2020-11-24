#ifndef INPUTCHOICE_RULE_H
#define INPUTCHOICE_RULE_H
#include "AstNode.h"
#include <string>

class InputChoiceRule : public AstNode
{
    public:
    InputChoiceRule(string, string, string, string,int);
    void execute(State&) override;
    void print() override;
    void accept(AstVisitor& visitor, State& gameState) override;
    Player getPlayer();
    vector<GameVariant> getChoiceList();
    std::string getCompletePrompt();
    int getTimeOut();
    std::string getResult();
    private:
    string rule;
    string to;
    Player toPlayer;
    string prompt;
    string completePrompt;
    string choices;
    vector<GameVariant> choiceList;
    string result;
    int timeout;

};
#endif
