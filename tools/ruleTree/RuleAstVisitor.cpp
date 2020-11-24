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

RuleAstVisitor::RuleAstVisitor()
{
}
void RuleAstVisitor::visit(GlobalMessage &globalMessage, State &gameState)
{
    //TODO: Decipher the "{}"
    //TO DO: Push the cout statement to a message Queue to throw to server side
    std::cout << globalMessage.getMessage() << endl;
}
void RuleAstVisitor::visit(DiscardRule &discard, State &gameState)
{
    std::cout << "This is DiscardRule visit function" << std::endl;
}
void RuleAstVisitor::visit(ExtendRule &extend, State &gameState)
{
    std::cout << "This is ExtendRule visit function" << std::endl;
}
void RuleAstVisitor::visit(ForEachRule &forEachRule, State &gameState)
{
    //TODO: turn the "list" and "element" variables into a actual thing we can use
    
    forEachRule.execute(gameState);
    // this should be done by calling execute funtion in obj Element and List
    std::cout << "This is ForEachRule visit function" << std::endl;
    //forEachRule.setNumLoop(forEachRule.getList().getList().size());
    forEachRule.setNumLoop(forEachRule.getList().getTest().size());

    vector<AstNode *> ruleList = forEachRule.getRuleList();
    for (int i = 0; i < forEachRule.getNumLoop(); i++)
    {
        RuleAstVisitor visitor;
        for (auto i : ruleList)
        {
            i->accept(visitor, gameState);
        }
        std::cout << std::endl;
    }
}
void RuleAstVisitor::visit(InputChoiceRule &inputChoice, State &gameState)
{
    std::cout << "This is InputChoiceRule visit function" << std::endl;
    //TODO: : Somehow ask the player for their input

    vector<Player> list = gameState.getPlayers();
    // TODO: Loop through the Player list ask for input
    // and put the input in to the each Player obj
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

void RuleAstVisitor::visit(AddRule &addRule, State &gameState)
{
    std::cout << "This is AddRule visit function" << std::endl;
}