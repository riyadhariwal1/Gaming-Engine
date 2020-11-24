#include "RuleAstVisitor.h"
#include "GlobalMessage.h"
#include "Extend.h"
#include "When.h"
#include "Discard.h"
#include "ForEach.h"
#include "ParallelFor.h"
#include "Player.h"
#include "InputChoice.h"
#include "Scores.h"
#include <iostream>
#include <string>
#include <future> // std::async, std::future
#include <chrono> // std::chrono::milliseconds

RuleAstVisitor::RuleAstVisitor()
{
}
void RuleAstVisitor::visit(GlobalMessage &globalMessage, State &gameState)
{
    //TODO: Decypher the "{}"
    //TO DO: Push the cout statement to a message Queue to throw to server side
    globalMessage.execute(gameState);
    std::cout << globalMessage.getCompleteMessage() << endl;
}
void RuleAstVisitor::visit(DiscardRule &discard, State &gameState)
{
    discard.execute(gameState);
    std::cout << "This is DiscardRule visit function" << std::endl;
}
void RuleAstVisitor::visit(ExtendRule &extend, State &gameState)
{
    std::cout << "This is ExtendRule visit function" << std::endl;
}
void RuleAstVisitor::visit(ForEachRule &forEachRule, State &gameState)
{
    //TODO: turn the "list" and "element" variables into a actual thing we can use
    // this should be done by calling execute funtion in obj Element and List
    std::cout << "This is ForEachRule visit function" << std::endl;
    vector<AstNode *> ruleList = forEachRule.getRuleList();

    RuleAstVisitor visitor;
    for (auto i : ruleList)
    {
        i->accept(visitor, gameState);
    }
}

//InputChoice Rule implementation
string getInputFromUser()
{
    string input;
    cin >> input;
    return input;
}
void RuleAstVisitor::visit(InputChoiceRule &inputChoice, State &gameState)
{
    std::cout << "This is InputChoiceRule visit function" << std::endl;
    //TODO: : Somehow ask the player for their input

    //vector<Player> list = gameState.getPlayers();
    //inputChoice.execute(gameState);
    //cout<<inputChoice.getCompletePrompt()<<endl;
    //TODO: ask for list of choices

    // TODO: Ask for input from chosen one
    int timeout = inputChoice.getTimeOut();
    std::future<string> task = std::async(std::launch::async, getInputFromUser);
    string result;
    if (std::future_status::ready == task.wait_for(std::chrono::seconds(timeout)))
    {
        result = task.get();
    }
    else
    {
        cout << "user doesnt enter input" << endl;
    }
    //TODO: Map result to variable
}

void RuleAstVisitor::visit(ParallelFor &parallelFor, State &gameState)
{
    //TODO: Same as foreach
    std::cout << "This is ParallelFor visit function" << std::endl;
    vector<AstNode *> ruleList = parallelFor.getRuleList();

    RuleAstVisitor visitor;
    for (auto i : ruleList)
    {
        i->accept(visitor, gameState);
    }
}
void RuleAstVisitor::visit(ScoreRule &scores, State &gameState)
{
    std::cout << "This is ScoreRule visit function" << std::endl;
}

void RuleAstVisitor::visit(WhenRule &whenRule, State &gameState)
{
    std::cout << "This is WhenRule visit function" << std::endl;
}

void RuleAstVisitor::visit(Element &element, State &gameState)
{
    //TODO
    std::cout << "This is Element visit function" << std::endl;
}
void RuleAstVisitor::visit(List &list, State &gameState)
{
    std::cout << "This is List visit function" << std::endl;
}