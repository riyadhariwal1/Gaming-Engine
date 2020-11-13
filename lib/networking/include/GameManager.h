#ifndef WEBSOCKETNETWORKING_GAME_MANAGER_H
#define WEBSOCKETNETWORKING_GAME_MANAGER_H

#include <iostream>
#include <algorithm>
#include "Server.h"
#include "Game.h"

class GameManager{
    private:
        std::vector<Game> gameList;
    public:
        GameManager(std::vector<Game> newList);
        void addGame(Game game);
        void deleteGame(Game game);
        void deleteLastGame();
        int findGameIndex(Game game);
};

#endif
