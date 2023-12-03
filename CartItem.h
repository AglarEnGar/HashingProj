#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"

class CartItem {
public:
  CartItem(const Product &product, int quantity);
  const Product& getProduct() const;
  int getQuantity() const;
  double getTotalPrice() const;

private:
  Product product;
  int quantity;
};

#endif // CARTITEM_H
