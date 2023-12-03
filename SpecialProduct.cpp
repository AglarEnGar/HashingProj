#include "SpecialProduct.h"

SpecialProduct::SpecialProduct(int id, const std::string &name, double price, const std::string &feature)
    : Product(id, name, price), specialFeature(feature) {}

std::string SpecialProduct::getSpecialFeature() const {
  return specialFeature;
}
