/** 
 * @file CartItem.h
 * @brief Defines the CartItem class for the OOP Shopping System.
 * 
 * This file provides the declaration of the CartItem class. CartItem extends the Product class,
 * representing a product within a shopping cart, including additional attributes like quantity,
 * and pointers to previous and next items in a linked list.
 * 
 * @author Luca, Canxin, Juan
 * @date 12/5/2023
 */

#ifndef CARTITEM_H
#define CARTITEM_H

#include "Product.h"

class CartItem : public Product {
private:
    Product cartItem;  /**< Product object representing the item in the cart */
    CartItem* prev;    /**< Pointer to the previous item in the cart */
    CartItem* next;    /**< Pointer to the next item in the cart */
    int quantity;      /**< Quantity of the product in the cart */

public:
    /** Default constructor */
    CartItem();

    /** Destructor */
    ~CartItem();

    /** Returns a pointer to the previous cart item */
    CartItem* getPrev();

    /** Returns a pointer to the next cart item */
    CartItem* getNext();

    /** Returns the product item */
    Product getItem();

    /** Returns the quantity of the product in the cart */
    int getQuantity() const;

    /** Sets the previous cart item */
    void setPrev(CartItem* newPrev);

    /** Sets the next cart item */
    void setNext(CartItem* newNext);

    /** Sets the product item */
    void setItem(Product newItem);

    /** Sets the quantity of the product in the cart */
    void setQuantity(int newQuantity);

    /**
     * Generates a string for menu item display.
     * @return String representation of the cart item for menu items.
     * Note: Requires appending 'endl' when printed.
     */
    [[nodiscard]] std::string toMenuItemString() const override;

    /**
     * Generates a CSV format string for the cart item.
     * @return CSV formatted string of the cart item.
     * Format: 'Product ID,Product Name,Price,Description,Quantity'
     * Note: 'endl' is needed after printing.
     */
    [[nodiscard]] std::string toCSVString() const override;
};

#endif // CARTITEM_H
