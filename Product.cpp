#include "Product.h"

Product::Product(int id, const std::string &name, double price)
    : productId(id), name(name), price(price) {}

int Product::getId() const {
  return productId;
}

std::string Product::getName() const {
  return name;
}

double Product::getPrice() const {
  return price;
}
