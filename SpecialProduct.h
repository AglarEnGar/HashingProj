#ifndef SPECIALPRODUCT_H
#define SPECIALPRODUCT_H

#include "Product.h"
#include <string>

class SpecialProduct : public Product {
public:
  SpecialProduct(int id, const std::string &name, double price, const std::string &feature);
  std::string getSpecialFeature() const;

private:
  std::string specialFeature;
};

#endif // SPECIALPRODUCT_H
