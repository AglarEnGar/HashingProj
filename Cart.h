#ifndef CART_H
#define CART_H

#include "CartItem.h"
#include <list>

class Cart {
public:
  void addItem(const CartItem& item);
  void removeItem(int productId);
  double calculateTotal() const;
  void displayCart() const; // 用于展示购物车中的商品

private:
  std::list<CartItem> items;
};

#endif // CART_H
