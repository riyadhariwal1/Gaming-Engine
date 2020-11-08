
#ifndef SOCIAL_GAMING_ASTNODE_H
#define SOCIAL_GAMING_ASTNODE_H

//visitable interface
class astNode {
public:
    virtual void accept(astVisitor& visitor) = 0;
};


#endif
