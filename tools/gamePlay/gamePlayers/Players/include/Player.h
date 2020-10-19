#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player {
    public:
      Player();
      Player(std::string& name);
      void playerWins(int count);
      void printPlayer();
      // define player "Type"? -- game-player or audience-player

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
