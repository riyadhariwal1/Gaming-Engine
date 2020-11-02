#include <iostream>
#include "../include/game.h"

void Game::setGameId(int id){
	this->gameId = id;
}

int Game::getGameId() const{
	return gameId;
}

void Game::setName(std::string newName){
	this->name = newName;
}

std::string Game::getName() const{
	return name;
}

void Game::setPath(std::string path){
	this->filePath = path;
}

std::string Game::getPath() const{
	return filePath;
}
