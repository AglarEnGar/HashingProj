#ifndef CART_H
#define CART_H
#include "CartItem.h"

class Cart {
private:
    CartItem* head;
    CartItem* tail;
    int sizeCart = 0;
    // 3 func used for mergeSortCart
    CartItem*mergeSortPrice(CartItem* head);
    CartItem*getMidNode2Split(CartItem* head);
    CartItem*sortedMergePrice(CartItem* a, CartItem* b);
    //merge sort by name
    CartItem*mergeByName(CartItem* a, CartItem* b);
    CartItem*sortNMergeByName(CartItem* head);

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
    CartItem * split(CartItem* head);
    void priceMergeSortCart();
    void nameMergeSortCart();


    //void quicksortCart();
    //void insertionSortCart();
};

#endif