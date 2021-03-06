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
#include "Add.h"
#include <iostream>
#include <string>
#include <future> // std::async, std::future
#include <chrono> // std::chrono::milliseconds

RuleAstVisitor::RuleAstVisitor()
{}

// Independent use of Rule class
void RuleAstVisitor::visit(GlobalMessage &globalMessage, State &gameState)
{
    //TODO: Decipher the "{}"
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
string getInputFromUser( atomic_bool &cancelled)
{
    string input;
    while (!cancelled)
    {
        //ToDo: Get input from user
        //this_thread::sleep_for(chrono::seconds(12));
    }
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
    atomic_bool cancellation_token= ATOMIC_VAR_INIT(false);
    int timeout = inputChoice.getTimeOut();
    std::chrono::seconds chronoTimeout(timeout);
    std::future<string> task = std::async(launch::async, getInputFromUser, ref(cancellation_token));
    string result;
    cout<<std::chrono::seconds(chronoTimeout).count()<<endl;
    if (std::future_status::ready == task.wait_for(std::chrono::seconds(10)))
    {
        result = task.get();
    }
    else
    {
        cout << "user doesnt enter input" << endl;
        cancellation_token = ATOMIC_VAR_INIT(true);
    }
    //TODO: Map result to variable
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

void RuleAstVisitor::visit(AddRule &addRule, State& gameState) {
    std::cout << "This is Add Rule visit function" << std::endl;
}



// ForEachRule and ParrarellRule cases
void RuleAstVisitor::visit(GlobalMessage &globalMessage, State &gameState, List& list, Element& element)
{
    //TODO: Decipher the "{}"
    //TO DO: Push the cout statement to a message Queue to throw to server side
    globalMessage.execute(gameState, list, element);
    std::cout << globalMessage.getCompleteMessage() << endl;
}

void RuleAstVisitor::visit(DiscardRule &discard, State &gameState, List& list, Element& element)
{
    discard.execute(gameState, list, element);
    std::cout << "This is DiscardRule visit function" << std::endl;
}

void RuleAstVisitor::visit(ExtendRule &extend, State &gameState, List& list, Element& element)
{
    std::cout << "This is ExtendRule visit function" << std::endl;
}
void RuleAstVisitor::visit(InputChoiceRule &inputChoice, State &gameState, List& list, Element& element)
{
    std::cout << "This is InputChoiceRule visit function" << std::endl;
    //TODO: : Somehow ask the player for their input

    //vector<Player> list = gameState.getPlayers();
    //inputChoice.execute(gameState);
    //cout<<inputChoice.getCompletePrompt()<<endl;
    //TODO: ask for list of choices

    // TODO: Ask for input from chosen one
    atomic_bool cancellation_token= ATOMIC_VAR_INIT(false);
    //int timeout = inputChoice.getTimeOut();
    // just to make the code run faster uncomment the upper line to make it run correctly
    int timeout = 2;
    // testing
    std::chrono::seconds chronoTimeout(timeout);
    std::future<string> task = std::async(launch::async, getInputFromUser, ref(cancellation_token));
    string result;
    cout<<std::chrono::seconds(chronoTimeout).count()<<endl;
    if (std::future_status::ready == task.wait_for(std::chrono::seconds(10)))
    {
        result = task.get();
    }
    else
    {
        cout << "user doesnt enter input" << endl;
        cancellation_token = ATOMIC_VAR_INIT(true);
    }
    //TODO: Map result to variable
}
void RuleAstVisitor::visit(ForEachRule &forEachRule, State &gameState, List& list , Element& element)
{

    forEachRule.execute(gameState);
    std::cout << "This is ForEachRule visit function nested version" << std::endl;
    List nestedList = forEachRule.getList();
    std::cout << "Numloop in nested == " << forEachRule.getNumLoop() << std:: endl;
    std::vector<std::unique_ptr<AstNode>> const& ruleList = forEachRule.getRuleList();
    std::cout << "Rule list in nested == " << ruleList.size() << std:: endl;

    for (int y = 0; y < forEachRule.getNumLoop(); y++) {
        Element nestedElement = forEachRule.getElement();
        RuleAstVisitor visitor;
        for (auto & i : ruleList) {
            i->accept(visitor, gameState, nestedList, nestedElement);
        }
        std::cout << std::endl;
        forEachRule.getElement().indexIncrement();
    }
}
void RuleAstVisitor::visit(ParallelFor &parallelFor, State &gameState, List& list, Element& element)
{
    //TODO: Same as foreach
    std::cout << "This is ParallelFor visit function" << std::endl;
    std::vector<std::unique_ptr<AstNode>> const& ruleList = parallelFor.getRuleList();

    RuleAstVisitor visitor;
    for (auto & i : ruleList)
    {
        i->accept(visitor, gameState, list, element);
    }
}


void RuleAstVisitor::visit(ScoreRule &scores, State &gameState, List& list, Element& element)
{
    std::cout << "This is ScoreRule visit function" << std::endl;
}

void RuleAstVisitor::visit(WhenRule &whenRule, State &gameState, List& list, Element& element)
{
    std::cout << "This is WhenRule visit function" << std::endl;
}
void RuleAstVisitor::visit(AddRule &addRule, State& gameState, List& list, Element& element) {
    std::cout << "This is Add Rule visit function" << std::endl;
}


// ForEach and ParallelFor Rule
void RuleAstVisitor::visit(ForEachRule &forEachRule, State &gameState)
{

    forEachRule.execute(gameState);
    std::cout << "This is ForEachRule visit function" << std::endl;
    List list = forEachRule.getList();
    std::cout << "Numloop == " << forEachRule.getNumLoop() << std:: endl;
    std::vector<std::unique_ptr<AstNode>> const& ruleList = forEachRule.getRuleList();
    std::cout << "Rule list == " << ruleList.size() << std:: endl;

    for (int y = 0; y < forEachRule.getNumLoop(); y++) {
        Element element = forEachRule.getElement();
        RuleAstVisitor visitor;
        for (auto & i : ruleList) {
            i->accept(visitor, gameState, list, element);
        }
        std::cout << std::endl;
        forEachRule.getElement().indexIncrement();
    }
}

void RuleAstVisitor::visit(ParallelFor &parallelFor, State &gameState)
{
    //TODO: Same as foreach
    std::cout << "This is ParallelFor visit function" << std::endl;
    std::vector<std::unique_ptr<AstNode>> const& ruleList = parallelFor.getRuleList();

    RuleAstVisitor visitor;
    for (auto & i : ruleList)
    {
        i->accept(visitor, gameState);
    }
}
