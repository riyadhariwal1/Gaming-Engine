#ifndef FOREACH_RULE_H
#define FOREACH_RULE_H
#include "Rule.h"
#include "GameState.h"
#include <string>
#include <boost/any.hpp>
using namespace std;

class ForEachRule : public Rule
{
    public:
    ForEachRule(std::list<boost::any>, int);
    void execute(GameState&) override;
};
#endif
