#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
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



//List of Players - yet to implement
class AllPlayers{
private:
    vector<Player> playerList;

public:
    void addPlayer(Player player);
    vector<Player> getList();
};
#endif