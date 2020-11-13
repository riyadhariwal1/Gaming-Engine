#include "Store.h"

void Store::addUser(User& user) {
  this->users.push_back(user);
}

void Store::removeUser(networking::Connection c) {
  for (auto u : this->users)
  {
    if (u.getConnection() == c)
    {
      auto eraseBegin = std::remove(std::begin(users), std::end(users), u);
      users.erase(eraseBegin, std::end(users));
    }
  }
}

void Store::addRoom(Room& room) {
  this->rooms.push_back(room);
}

User* Store::getUserByConnection(Connection c)
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
