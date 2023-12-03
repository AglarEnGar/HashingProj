#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
  Product(int id, const std::string &name, double price);
  int getId() const;
  std::string getName() const;
  double getPrice() const;

private:
  int productId;
  std::string name;
  double price;
};

#endif // PRODUCT_H
