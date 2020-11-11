#ifndef ELEMENT_H
#define ELEMENT_H
#include "AstNode.h"

using namespace std;

class Element: public AstNode{
    private:
        string value;
        AstNode* target;

    public:
        Element();
        AstNode* getTarget();
        Element(string);
        void execute(GameState&);
        void print()
        {
            cout << value << endl;
        }
        void accept(AstVisitor& visitor) override;

};

#endif