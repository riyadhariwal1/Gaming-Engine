#ifndef SOCIAL_GAMING_RULEASTVISITOR_H
#define SOCIAL_GAMING_RULEASTVISITOR_H
#include "AstVisitor.h"
#include <vector>
#include "AstNode.h"

class RuleAstVisitor : public AstVisitor
{
public:

    RuleAstVisitor();
    void visit(GlobalMessage &globalMessage, State& gameState);
    void visit(GlobalMessage &globalMessage, State& gameState, List& list, Element& element);

    void visit(DiscardRule &discard, State& gameState);
    void visit(DiscardRule &discard, State& gameState, List& list, Element& element);

    void visit(ExtendRule &extend, State& gameState);
    void visit(ExtendRule &extend, State& gameState, List& list, Element& element);

    void visit(ForEachRule &forEachRule, State& gameState);
    void visit(ForEachRule &forEachRule, State& gameState, List& list, Element& element);

    
    void visit(InputChoiceRule &inputChoice, State &gameState);
    void visit(InputChoiceRule &inputChoice, State& gameState, List& list, Element& element);

    void visit(ParallelFor &parallelFor, State& gameState);
    void visit(ParallelFor &parallelFor, State& gameState, List& list, Element& element);


    void visit(ScoreRule &scores, State& gameState);
    void visit(ScoreRule &scores, State& gameState, List& list, Element& element);

    void visit(WhenRule &whenRule, State& gameState);
    void visit(WhenRule &whenRule, State& gameState, List& list, Element& element);

    void visit(Element &element, State& gameState);
    void visit(List &list, State& gameState);

    void visit(AddRule &addRule, State& gameState);
    void visit(AddRule &addRule, State& gameState, List& list, Element& element);

};

#endif