#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player {
    public:
      explicit Player(std::string& name);
      void playerWins(int count);
      void printPlayer();

    private:
      int id;
      std::string& name;
      int gameWins;
};
#endif

/*
List of Players
class AllPlayers{

}*/
