#ifndef NETWORKING_STORE_H
#define NETWORKING_STORE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "User.h"
#include "Room.h"
#include "Server.h"

/**
 * @class Store
 *
 * @brief Holds the rooms and users for the server
 *
 * The Store class is intended to manage the all the rooms and users of the server,
 * while providing easy, de-coupled access. All reads/writes will be done through
 * the class methods.
 */
class Store {
private:
  std::vector<User> users;
  std::vector<Room> rooms;

public:
  Store() {
    rooms.push_back(Room{0, "Main"});
  }
  std::vector<User>* getUsers() { return &users; }
  std::vector<Room>* getRooms() { return &rooms; }
  void addUser(User&);
  void removeUser(networking::Connection c);
  void addRoom(Room&);
  User* getUserByConnection(networking::Connection c);
  User* getUserByName(std::string name);
  Room* getLobby() { return &rooms.at(0); };
  Room* getRoomByName(std::string roomName);
  Room* getRoomById(int roomId);
  // DEBUG
  // prints all the rooms and their users
  void print();
};

#endif
