#ifndef WEBSOCKETNETWORKING_ROOM_H
#define WEBSOCKETNETWORKING_ROOM_H
#include "User.h"


class Room {
private:
    int roomId;
    std::string name;
    std::vector<User> users;

public:
    Room(){
        roomId = 0;
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
};


#endif //WEBSOCKETNETWORKING_ROOM_H
