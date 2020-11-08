#ifndef SOCIAL_GAMING_ASTVISITOR_H
#define SOCIAL_GAMING_ASTVISITOR_H

#include "Rule.h"
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

//visitor interface
class astVisitor {
public:
    virtual void visit(astNode& node) = 0;
    virtual void visit(GlobalMessage& globalMessage) = 0;
    virtual void visit(Add& add) = 0;
    virtual void visit(Discard& discard) = 0;
    virtual void visit(Extend& extend) = 0;
    virtual void visit(ForEachRule& forEachRule) = 0;
    virtual void visit(InputChoice& inputChoice) = 0;
    virtual void visit(ParallelFor& parallelFor) = 0;
    virtual void visit(Scores& scores) = 0;
    virtual void visit(WhenRule& whenRule) = 0;

};

#endif //SOCIAL_GAMING_ASTVISITOR_H
