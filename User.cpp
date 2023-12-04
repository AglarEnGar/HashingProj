#include "User.h"

User::User(int userId, const std::string &username, const std::string &passwordHash)
    : userId(userId), username(username), passwordHash(passwordHash) {}

int User::getUserId() const {
  return userId;
}

const std::string& User::getUsername() const {
  return username;
}

bool User::validatePassword(const std::string &inputPasswordHash) const {
  return inputPasswordHash == passwordHash;
}

Cart& User::getCart() {
  return cart;
}
