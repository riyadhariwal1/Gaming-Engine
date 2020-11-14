#include "Store.h"

void Store::addUser(User& user) {
  users.push_back(user);
}

void Store::removeUser(networking::Connection c) {
  for (auto u : users)
  {
    if (u.getConnection() == c)
    {
      auto eraseBegin = std::remove(std::begin(users), std::end(users), u);
      users.erase(eraseBegin, std::end(users));
    }
  }
}

void Store::addRoom(Room& room) {
  rooms.push_back(room);
}

User*
Store::getUserByConnection(Connection c)
{
  for (auto &user : users)
  {
    if (user.connection == c)
      return &user;
  }
  std::cout << "Error. Trying to find user with Id " << c.id << "but they are not in the Users vector"
            << "\n";

  return nullptr;
}

User*
Store::getUserByName(std::string name){
  for (auto& user : users)
  {
    bool matches = name.compare(user.userName) == 0;
    if (matches) return &user;
  }

  return nullptr;
}

Room *
Store::getRoomByName(std::string roomName)
{
  for (auto &room : rooms)
  {
    if (room.getRoomName() == roomName) return &room;
  }

  return nullptr;
}

// given a room id, return a pointer to that Room otherwise return nullptr
Room *
Store::getRoomById(int roomId)
{
  for (auto &room : rooms)
  {
    if (room.getRoomId() == roomId) return &room;
  }

  return nullptr;
}
