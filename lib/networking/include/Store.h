#ifndef NETWORKING_STORE_H
#define NETWORKING_STORE_H

#include <vector>
#include "User.h"
#include "Room.h"

/**
 * @class Store
 *
 * @brief Holds the rooms and clients for the server
 *
 * The Store class is intended to manage the all the rooms and clients of the server,
 * while providing easy, de-coupled access. All reads/writes will be done through
 * the class methods.
 */
class Store {
private:
  std::vector<User> clients;
  std::vector<Room> rooms;

public:
  Store() {}
  std::vector<User> getUsers() { return clients; }
  std::vector<Room> getRooms() { return rooms; }
  void addUser(User&);
  void addRoom(Room&);
}

#endif
