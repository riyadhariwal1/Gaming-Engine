#ifndef WEBSOCKETNETWORKING_ROOM_H
#define WEBSOCKETNETWORKING_ROOM_H
#include "User.h"


class Room {
private:
    int roomId;
    std::vector<User> users;

public:
    Room(){
        roomId = 0;
    }
    Room(int Id){
        roomId = Id;
    }
    std::vector<User> getUsers() {return users;}
    int getRoomId(){return roomId;}
    void addUser(User);
    void removeUser(User);
    void printUsers();
};


#endif //WEBSOCKETNETWORKING_ROOM_H
