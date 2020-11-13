#ifndef WEBSOCKETNETWORKING_ROOM_H
#define WEBSOCKETNETWORKING_ROOM_H
#include "User.h"


class Room {
private:
    int roomId;
    std::string name;
    std::vector<User> users;
    std::string pin;

public:
    Room(){
        roomId = 0;
        pin = "";
    }
    Room(int Id, std::string roomName){
        roomId = Id;
        name = roomName;
    }
    std::vector<User> getUsers() {return users;}
    int getRoomId(){return roomId;}
    std::string getRoomName() {return name;}
    void addUser(User&);
    void removeUser(User&);
    void printUsers();
    bool containsUser(User&);
    std::string getPin(){return pin;}
    void setPin(std::string pin);
    bool verifyPin(std::string input);
    static std::string sanitizePin(std::string dirtyPin);
    bool isPrivate() {return pin != "";}
};


#endif //WEBSOCKETNETWORKING_ROOM_H
