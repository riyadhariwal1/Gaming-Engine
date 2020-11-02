#ifndef WEBSOCKETNETWORKING_USER_H
#define WEBSOCKETNETWORKING_USER_H

class Game{
private:
	int gameId;
	std::string name;
	std::string filePath;
public:
	Game(){gameId = 0;}
	Game(int Id, std::string gameName, std::string path){
		gameId = Id;
		name = gameName;
		filePath = path;
	}

	void setGameId(int id);
	int getGameId() const;
	void setName(std::string newName);
	std::string getName() const;
	void setPath(std::string path);
	std::string getPath() const;	
};
