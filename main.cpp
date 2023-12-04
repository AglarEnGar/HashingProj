#include "Store.h"
#include "User.h"
#include "Product.h"
#include "CartItem.h"
#include <iostream>
#include "test.h"

int main() {
  runTests();
  // 创建 Store
  Store myStore;

  // 添加一些商品到库存
  myStore.getInventory().addProduct(Product(1, "Apple", 0.99));
  myStore.getInventory().addProduct(Product(2, "Banana", 0.59));
  myStore.getInventory().addProduct(Product(3, "Orange", 0.79));

  // 注册一个用户
  User user(1, "JohnDoe", "password123");
  myStore.registerUser(user);

  // 用户添加商品到购物车
  Product* apple = myStore.getInventory().getProduct(1);
  Product* banana = myStore.getInventory().getProduct(2);
  if (apple && banana) {
    user.getCart().addItem(CartItem(*apple, 2)); // 2个苹果
    user.getCart().addItem(CartItem(*banana, 3)); // 3根香蕉
  }

  // 用户结账
  myStore.checkout(user.getUserId());

  return 0;
}
