#include "test.h"
#include "Product.h"
#include "CartItem.h"
#include "Inventory.h"
#include "Cart.h"
#include <iostream>

void testProduct() {
  Product product(1, "Apple", 0.99);
  if (product.getId() == 1 && product.getName() == "Apple" && product.getPrice() == 0.99) {
    std::cout << "Product Test Passed" << std::endl;
  } else {
    std::cout << "Product Test Failed" << std::endl;
  }
}

void testCartItem() {
  Product product(1, "Apple", 0.99);
  CartItem item(product, 5);
  if (item.getTotalPrice() == 4.95) {
    std::cout << "CartItem Test Passed" << std::endl;
  } else {
    std::cout << "CartItem Test Failed" << std::endl;
  }
}

void testInventory() {
  Inventory inventory;
  Product product(1, "Apple", 0.99);
  inventory.addProduct(product);

  if (inventory.getProduct(1) != nullptr) {
    std::cout << "Inventory Add Test Passed" << std::endl;
  } else {
    std::cout << "Inventory Add Test Failed" << std::endl;
  }

  inventory.removeProduct(1);
  if (inventory.getProduct(1) == nullptr) {
    std::cout << "Inventory Remove Test Passed" << std::endl;
  } else {
    std::cout << "Inventory Remove Test Failed" << std::endl;
  }
}

void testCart() {
  Cart cart;
  Product product(1, "Apple", 0.99);
  CartItem item(product, 5);
  cart.addItem(item);

  if (cart.calculateTotal() == 4.95) {
    std::cout << "Cart Add Test Passed" << std::endl;
  } else {
    std::cout << "Cart Add Test Failed" << std::endl;
  }
}

void runTests() {
  testProduct();
  testCartItem();
  testInventory();
  testCart();
}
