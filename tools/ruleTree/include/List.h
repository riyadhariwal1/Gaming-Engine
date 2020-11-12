#ifndef LIST_H
#define LIST_H
#include "AstNode.h"

using namespace std;
class List : public AstNode{
private:
    string value;
    vector <AstNode*> list;


public:
    List();
    vector<AstNode*> getList();
    List(string);
    void accept(AstVisitor& visitor) override;
    void execute(GameState&);
    void print();

};
#endif