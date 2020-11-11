#ifndef LIST_H
#define LIST_H
#include "Rule.h"

using namespace std;
class List : public Rule{
    private:
        string value;
        vector <Rule*> list;


    public:
        List();
        vector<Rule*> getList();
        List(string);
        void execute(GameState&);
        void print()
        {
            cout << value << endl;
        }

};
#endif