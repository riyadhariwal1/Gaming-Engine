#ifndef WEBSOCKETNETWORKING_USER_H
#define WEBSOCKETNETWORKING_USER_H

#include "../include/GameManager.h"

GameManager::GameManager(std::vector<Game> newList){
    gameList = newList;
}

void GameManager::addGame(Game game){
    gameList.push_back(game);
}

int GameManager::findGameIndex(Game game){
    for(int i=0;i<gameList.size();i++){
        if(gameList.at(i).getGameId() == game.getGameId() ){
            return i;
        }
    }
    std::cout<<"There is no such a game named: "<<game.getGameId<<".\n";
    return -1;
}

void GameManager::deleteGame(Game game){
    int index = gameList.findGameIndex(game);
    gameList.erase(index);
}

void GameManager::deleteLastGame(){
    gameList.pop_back();
}