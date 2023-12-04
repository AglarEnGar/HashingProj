#include "Inventory.h"

void Inventory::addProduct(const Product& product) {
  products.push_back(product);
}

void Inventory::removeProduct(int productId) {
  products.remove_if([&productId](const Product& product) {
    return product.getId() == productId;
  });
}

Product* Inventory::getProduct(int productId) {
  for (auto& product : products) {
    if (product.getId() == productId) {
      return &product;
    }
  }
  return nullptr;
}

void Inventory::listAllProducts(std::function<void(const Product&)> callback) const {
  for (const auto& product : products) {
    callback(product);
  }
}

void Inventory::sortProductsByPrice() {
  products.sort([](const Product& a, const Product& b) {
    return a.getPrice() < b.getPrice();
  });
}
