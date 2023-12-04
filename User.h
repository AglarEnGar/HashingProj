#ifndef USER_H
#define USER_H

#include "Cart.h"
#include <string>

class User {
public:
  User(int userId, const std::string &username, const std::string &passwordHash);
  int getUserId() const;
  const std::string& getUsername() const;
  bool validatePassword(const std::string &passwordHash) const;
  Cart& getCart();

private:
  int userId;
  std::string username;
  std::string passwordHash;
  Cart cart;
};

#endif // USER_H
