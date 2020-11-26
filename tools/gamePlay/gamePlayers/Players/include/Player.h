#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Parser.h"

using namespace std;

// Players Class
class Player {
    public:
      Player();
      Player(string name);
      void playerWins(int count);
      void printPlayer();
      void AddVariable(string givenKey, GameVariant givenValue);
      string getPlayerName();
      string getWithKey(string);
      // define player "Type"? -- game-player or audience-player

    private:
      int id;
      std::string name;
      int gameWins;
      // any variant inputs can be placed into this map;
      unordered_map<string,GameVariant> PlayerVariablesMap;
};

// All-Players Classs
class AllPlayers{
private:
    vector<Player> playerList;

public:
    void addPlayer(Player player);
    vector<Player> getList();
};
#endif
