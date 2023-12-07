#ifndef CARTITEM_H
#define CARTITEM_H
#include "Product.h"

class CartItem : public Product{
private:
    Product cartItem;
    CartItem* prev;
    CartItem* next;
    int quantity;
public:
    CartItem();
    ~CartItem();
    CartItem* getPrev();
    CartItem* getNext();
    Product getItem();
    int getQuantity();

    void setPrev(CartItem* newPrev);
    void setNext(CartItem* newNext);
    void setItem(Product newItem);
    void setQuantity(int newQuantity);

    std::string toString() const;
};

#endif