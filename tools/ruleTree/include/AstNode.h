#ifndef SOCIAL_GAMING_ASTNODE_H
#define SOCIAL_GAMING_ASTNODE_H


#include<string>
#include<iostream>
#include<vector>
#include "AstVisitor.h"
#include "GameState.h"
//visitable interface
class AstNode {
public:
    virtual void accept(AstVisitor& visitor) = 0;
    virtual void execute(GameState&) = 0;
    virtual void print () = 0;
};

#endif
