
// delete
/*请确保在使用 CartItem 类时，它所引用的 Product 对象在 CartItem 的整个生命周期内都有效。
 * 这通常意味着 Product 对象应该在被添加到 CartItem 之前就已经存在，例如存储在 Inventory 中。*/

#include "CartItem.h"

CartItem::CartItem(const Product &product, int quantity)
    : product(product), quantity(quantity) {}

const Product& CartItem::getProduct() const {
  return product;
}

int CartItem::getQuantity() const {
  return quantity;
}

double CartItem::getTotalPrice() const {
  return product.getPrice() * quantity;
}
