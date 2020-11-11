#ifndef ELEMENT_H
#define ELEMENT_H
#include "Rule.h"

using namespace std;

class Element: public Rule{
    private:
        string value;
        Rule* target;

    public:
        Element();
        Rule* getTarget();
        Element(string);
        void execute(GameState&);
        void print()
        {
            cout << value << endl;
        }

};

#endif