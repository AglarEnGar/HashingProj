#ifndef STORE_H
#define STORE_H

#include "User.h"
#include "Inventory.h"
#include <map>

class Store {
public:
  void registerUser(const User& user);
  User* getUser(int userId);
  void checkout(int userId);
  Inventory& getInventory();

private:
  std::map<int, User> users;
  Inventory inventory;
};

#endif // STORE_H
