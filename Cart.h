#ifndef CART_H
#define CART_H
#include "CartItem.h"

class Cart {
private:
    CartItem* head;
    CartItem* tail;
    int sizeCart = 0;
public:
    Cart();
    Cart(CartItem* newHead, CartItem* newTail);
    CartItem* getHead();
    CartItem* getTail();
    int size();

    void setHead(CartItem* newHead);
    void setTail(CartItem* newTail);

    void push_back(CartItem* newItem);
};

#endif