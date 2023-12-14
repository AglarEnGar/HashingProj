/** 
 * @file Cart.h
 * @brief Defines the Cart class for the OOP Shopping System.
 * 
 * This file provides the declaration of the Cart class. The Cart class represents a shopping cart
 * in the system, managing a collection of CartItem objects. It includes methods for adding,
 * removing items, and sorting the cart based on price or product name.
 * 
 * @author Luca, Canxin, Juan
 * @date 12/5/2023
 */

#ifndef CART_H
#define CART_H

#include "CartItem.h"

class Cart {
private:
    CartItem* head;  /**< Pointer to the first item in the cart */
    CartItem* tail;  /**< Pointer to the last item in the cart */
    int sizeCart;    /**< Number of items in the cart */

    // Methods used for merge sort by price
    CartItem* mergeSortPrice(CartItem* head);
    CartItem* getMidNode2Split(CartItem* head);
    CartItem* sortedMergePrice(CartItem* a, CartItem* b);

    // Methods for merge sort by name
    CartItem* mergeByName(CartItem* a, CartItem* b);
    CartItem* sortNMergeByName(CartItem* head);

public:
    /** Default constructor */
    Cart();

    /** Destructor */
    ~Cart();

    /** Parameterized constructor */
    Cart(CartItem* newHead, CartItem* newTail);

    /** Returns the head of the cart */
    CartItem* getHead();

    /** Returns the tail of the cart */
    CartItem* getTail();

    /** Returns the size of the cart */
    int size();

    /** Sets the head of the cart */
    void setHead(CartItem* newHead);

    /** Sets the tail of the cart */
    void setTail(CartItem* newTail);

    /** Removes an item from the cart */
    CartItem* removeItem(CartItem* item);

    /** Prints the cart items in a forward direction */
    void printForward();

    /** Adds a new item to the end of the cart */
    void push_back(CartItem* newItem);

    /** Sorts the cart items by price using merge sort */
    void priceMergeSortCart();

    /** Sorts the cart items by name using merge sort */
    void nameMergeSortCart();

    /** Sorts the cart items using selection sort */
    int selectionSort();

    /** Performs a linear search on the cart items */
    CartItem* linearSearch();

    /** Retrieves all matching items in the cart */
    void getAllMatches();
};

#endif // CART_H
