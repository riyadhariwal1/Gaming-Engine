#ifndef SOCIAL_GAMING_ASTVISITOR_H
#define SOCIAL_GAMING_ASTVISITOR_H

#include "GlobalMessage.h"
//#include "Discard.h"
//#include "Extend.h"
//#include "ForEach.h"
//#include "InputChoice.h"
//#include "ParallelFor.h"
//#include "Scores.h"
//#include "When.h"


//visitor interface
class AstVisitor {
public:
    //virtual void visit(AstNode& node) = 0;
    virtual void visit(GlobalMessage & globalMessage) = 0;
//    virtual void visit(Discard& discard) = 0;
//    virtual void visit(Extend& extend) = 0;
//    virtual void visit(ForEachRule& forEachRule) = 0;
//    virtual void visit(InputChoice& inputChoice) = 0;
//    virtual void visit(ParallelFor& parallelFor) = 0;
//    virtual void visit(Scores& scores) = 0;
//    virtual void visit(WhenRule& whenRule) = 0;

};

#endif //SOCIAL_GAMING_ASTVISITOR_H
