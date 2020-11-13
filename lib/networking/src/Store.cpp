#include "Store.h"

void Store::addUser(User& user) {
  this->clients.push_back(user);
}

void Store::addRoom(Room& room) {
  this->rooms.push_back(room);
}
