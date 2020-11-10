#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
using namespace std;

// convert to unordered_map<string,variant> ??
// string == id
// variant -> name, wins, input-choice will be placed in
class Player {
    public:
      Player();
      Player(string name);
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
