#ifndef SOCIAL_GAMING_ASTVISITOR_H
#define SOCIAL_GAMING_ASTVISITOR_H

#include "State.h"
class List;
class GlobalMessage;
class DiscardRule;
class ExtendRule;
class ForEachRule;
class InputChoiceRule;
class ParallelFor;
class ScoreRule;
class WhenRule;
class Element;
class AddRule;

//visitor interface
class AstVisitor {
public:
    //virtual void visit(AstNode& node) = 0;
    virtual void visit(GlobalMessage & globalMessage, State& gameState) = 0;
    virtual void visit(DiscardRule& discard, State& gameState) = 0;
    virtual void visit(ExtendRule& extend, State& gameState) = 0;
    virtual void visit(ForEachRule& forEachRule, State& gameState) = 0;
    virtual void visit(InputChoiceRule& inputChoice, State &gameState) = 0;
    virtual void visit(ParallelFor& parallelFor, State& gameState) = 0;
    virtual void visit(ScoreRule& scores, State& gameState) = 0;
    virtual void visit(WhenRule& whenRule, State& gameState) = 0;
    virtual void visit(Element& element, State& gameState) = 0;
    virtual void visit(List& list, State& gameState) = 0;
    virtual void visit(AddRule& addRule, State& gameState) = 0;

};

#endif //SOCIAL_GAMING_ASTVISITOR_H
