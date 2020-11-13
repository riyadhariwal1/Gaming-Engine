#ifndef WEBSOCKETNETWORKING_GAME_H
#define WEBSOCKETNETWORKING_GAME_H

class Game{
private:
	int gameId;
	std::string name;
	std::string filePath;
	std::string description;
	int maxPlayer;
	int current_player;
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
	void setDescription(std::string descrip);
	std::string getDescription() const;

};

#endif
