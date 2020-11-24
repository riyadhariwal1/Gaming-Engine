#ifndef LIST_H
#define LIST_H
#include "AstNode.h"

using namespace std;
class List : public AstNode{
private:
    string value;
    vector <AstNode*> list;

    vector<int> test;


public:
    List();
    vector<AstNode*> getList();
    vector<int> getTest(); // testing
    List(string);
    void accept(AstVisitor& visitor, State& gameState) override;
    void execute(State&);
    void print();

};
#endif
