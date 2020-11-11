#include <iostream>
#include <algorithm>
#include <regex>
#include "../include/Room.h"

// returns true if valid pin, false if not
bool Room::validatePin(std::string dirtyPin) {
    std::regex pattern("^[0-9]{4}$");
    auto matches = std::regex_match(dirtyPin, pattern);

    if (!matches) throw "Pin is not valid";

    return matches;
}

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

// sets the room pin and returns true if successful
bool Room::setPin(std::string pin) {
    try {
        const auto isValidPin = this->validatePin(pin);

        if (isValidPin) {
            this->pin = pin;
            return true;
        }
    } catch (const char* err) {
        throw err;
    }

    return false;
}

// Verify the pin
// If the room doesn't have a pin we return true
// This checks for a valid 4-digit numerical pin
bool Room::verifyPin(std::string input) {
    std::string roomPin = this->getPin();

    if (roomPin == "") return true;

    const auto isValidPin = this->validatePin(input);

    return isValidPin ? roomPin == input : false;
}
