#include <iostream>
#include <algorithm>
#include "../include/Room.h"

void Room::addUser(User& user) {
    std::cout << "Adding User: " << user.connection.id << " to room " << roomId << "\n";

    user.roomId = roomId;
    users.push_back(user);
}

void Room::removeUser(User& user) {
    std::cout << "Removing User: " << user.connection.id << " from room " << roomId << "\n";

    auto eraseBegin = std::remove(std::begin(users), std::end(users), user);
    users.erase(eraseBegin, std::end(users));

    user.roomId = 0;
}

bool Room::containsUser(User& user) {
    auto result = std::find(users.begin(), users.end(), user);

    if (result != std::end(users)) {
        return true;
    }

    return false;
}

void Room::printUsers(){
    std::cout<<"Room:"<<roomId<<"\n";

    for (auto user:users){
        std::cout<<user.connection.id<<"\n";
    }
    std::cout<<"__________________________"<<"\n"<<"\n";
}
