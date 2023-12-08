#ifndef CART_H
#define CART_H
#include "CartItem.h"

class Cart {
private:
    CartItem* head;
    CartItem* tail;
    int sizeCart = 0;
    // 3 func used for mergeSortCart
    CartItem* mergeSort(CartItem* head);
    CartItem* split(CartItem* head);
    CartItem* sortedMerge(CartItem* a, CartItem* b);
public:
    Cart();
    ~Cart();
    Cart(CartItem* newHead, CartItem* newTail);
    CartItem* getHead();
    CartItem* getTail();
    int size();

    void setHead(CartItem* newHead);
    void setTail(CartItem* newTail);
    CartItem* removeItem(CartItem* item);
    void printForward();
    void push_back(CartItem* newItem);

    void mergeSortCart();
    void quicksortCart();
    void insertionSortCart();
};

#endif