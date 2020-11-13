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
    std::cout<<"There is no such a game named: "<< game.getGameId() <<".\n";
    return -1;
}

void GameManager::deleteGame(Game game){
    auto index = this->findGameIndex(game);
    this->gameList.erase(this->gameList.begin() + index);
}

void GameManager::deleteLastGame(){
    gameList.pop_back();
}
