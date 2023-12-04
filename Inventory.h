#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include <list>
#include <algorithm>
#include <functional>

class Inventory {
public:
  void addProduct(const Product& product);
  void removeProduct(int productId);
  Product* getProduct(int productId);
  void listAllProducts(std::function<void(const Product&)> callback) const;
  void sortProductsByPrice();

private:
  std::list<Product> products;
};

#endif // INVENTORY_H
