#include "Cart.h"
#include <iostream>

void Cart::addItem(const CartItem& item) {
  items.push_back(item);
}

void Cart::removeItem(int productId) {
  items.remove_if([&productId](const CartItem& item) {
    return item.getProduct().getId() == productId;
  });
}

double Cart::calculateTotal() const {
  double total = 0.0;
  for (const auto& item : items) {
    total += item.getTotalPrice();
  }
  return total;
}

void Cart::displayCart() const {
  for (const auto& item : items) {
    std::cout << "Product: " << item.getProduct().getName()
              << ", Quantity: " << item.getQuantity()
              << ", Total Price: " << item.getTotalPrice() << std::endl;
  }
}
