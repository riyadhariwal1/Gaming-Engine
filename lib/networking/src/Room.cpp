#include <iostream>
#include <algorithm>
#include <regex>
#include "../include/Room.h"

// A util function to validate pins out of the Room context
// This can probably be kept as a namespaced function and not part of the Room class
std::string Room::sanitizePin(std::string pin) {
    std::regex pattern("^[0-9]{4}$");
    auto matches = std::regex_match(pin, pattern);

    if (!matches) throw "Pin is invalid.";

    return pin;
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
void Room::setPin(std::string pin) {
    try {
        const auto sanitizedPin = this->sanitizePin(pin);

        this->pin = sanitizedPin;
        return;
    } catch (const char* err) {
        throw err;
    }

    return;
}

// Verify the pin
// If the room doesn't have a pin we return true
// This checks for a valid 4-digit numerical pin
bool Room::verifyPin(std::string input) {
    if (!this->isPrivate()) return false;

    const auto sanitizedPin = this->sanitizePin(input);

    return this->getPin() == sanitizedPin;
}

void Room::setGame(Game* game) {
    this->currentGame = game;
}

std::deque<networking::Message>
Room::getGameMessages() {

};
