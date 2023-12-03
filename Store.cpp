#include "Store.h"

void Store::registerUser(const User& user) {
  users[user.getUserId()] = user;
}

User* Store::getUser(int userId) {
  auto it = users.find(userId);
  if (it != users.end()) {
    return &(it->second);
  }
  return nullptr;
}

void Store::checkout(int userId) {
  User* user = getUser(userId);
  if (user) {
    // 处理结账逻辑
    // 这里可以添加更新库存、处理支付等逻辑
    user->getCart().calculateTotal(); // 示例，计算总价
    user->getCart().displayCart();    // 示例，显示购物车内容
  }
}

Inventory& Store::getInventory() {
  return inventory;
}

