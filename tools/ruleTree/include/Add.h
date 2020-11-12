#ifndef ADD_RULE_H
#define ADD_RULE_H
#include "AstVisitor.h"
#include "AstNode.h"
#include "GameState.h"
#include "Player.h"
#include <string>
using namespace std;

class AddRule {
public:
    AddRule(Player& variable, int count);
};
#endif
