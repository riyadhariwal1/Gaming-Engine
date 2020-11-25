#ifndef LIST_H
#define LIST_H
#include "AstNode.h"

using namespace std;
class List : public AstNode{
private:
    string value;
    vector <GameVariant> list;


public:
    List();
    vector<GameVariant> getList();
    List(string);
    void accept(AstVisitor& visitor, State& gameState) override;
    void execute(State&);
    void print();

};
#endif
