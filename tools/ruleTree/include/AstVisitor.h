#ifndef SOCIAL_GAMING_ASTVISITOR_H
#define SOCIAL_GAMING_ASTVISITOR_H

class GlobalMessage;
class DiscardRule;
class ExtendRule;
class ForEachRule;
class InputChoiceRule;
class ParallelFor;
class ScoreRule;
class WhenRule;
class List;


//visitor interface
class AstVisitor {
public:
    //virtual void visit(AstNode& node) = 0;
    virtual void visit(GlobalMessage & globalMessage) = 0;
    virtual void visit(DiscardRule& discard) = 0;
    virtual void visit(ExtendRule& extend) = 0;
    virtual void visit(ForEachRule& forEachRule) = 0;
    virtual void visit(InputChoiceRule& inputChoice) = 0;
    virtual void visit(ParallelFor& parallelFor) = 0;
    virtual void visit(ScoreRule& scores) = 0;
    virtual void visit(WhenRule& whenRule) = 0;

};

#endif //SOCIAL_GAMING_ASTVISITOR_H
