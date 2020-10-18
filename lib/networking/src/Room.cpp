#include <iostream>
#include "../include/Room.h"

void Room::addUser(User user) {
    std::cout << "Adding User: " << user.connection.id << " to room " << roomId << "\n";
    user.roomId = this->roomId;
    users.push_back(user);
}

void Room::removeUser(User user) {
    std::cout << "Removing User: " << user.connection.id << " from room " << roomId << "\n";
    auto eraseBegin = std::remove(std::begin(users), std::end(users), user);
    users.erase(eraseBegin, std::end(users));
}
//bool Room::containsUser(User user){
//
//}
void Room::printUsers(){
    std::cout<<"Room:"<<roomId<<"\n";

    for (auto user:users){
        std::cout<<user.connection.id<<"\n";
    }
    std::cout<<"__________________________"<<"\n"<<"\n";
}