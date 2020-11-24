#ifndef SOCIAL_GAMING_ASTNODE_H
#define SOCIAL_GAMING_ASTNODE_H

#include<string>
#include<iostream>
#include<vector>
#include "AstVisitor.h"
#include "State.h"
#include "Player.h"
//visitable interface
//class List;
//class Element;

class AstNode {
public:
    virtual void accept(AstVisitor& visitor, State& ) = 0;
    virtual void execute(State&) = 0;
    virtual void print () = 0;
};

#endif
