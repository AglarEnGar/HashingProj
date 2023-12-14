/** 
 * @file Inventory.h
 * @brief Defines the Inventory class for the OOP Shopping System.
 * 
 * This file provides the declaration of the Inventory class. The Inventory class is responsible
 * for managing a collection of products available in the store. It utilizes an unordered map
 * to store products, allowing for efficient retrieval, insertion, and deletion of products 
 * based on their names.
 * 
 * @author Luca, Canxin, Juan
 * @date 12/5/2023
 */

#ifndef HASHING_INVENTORY_H
#define HASHING_INVENTORY_H

#include "Product.h"
#include <unordered_map>

class Inventory{
private:
    std::unordered_map<std::string, Product> *inv1; /**< Unordered map storing products keyed by name */

public:
    /** Default constructor */
    Inventory();

    /** Destructor */
    ~Inventory();

    /** Retrieves a product by name */
    Product * getFromName(std::string name) const;

    /** Deletes a product by name */
    void delFromName(std::string name);

    /** Inserts a new product into the inventory */
    void insert(const Product &p);

    /** Prints all products in the inventory */
    void printall();

    /** Returns the number of products in the inventory */
    unsigned int size() const;

    /** Returns the quantity of a specific product in the inventory */
    unsigned int itemQuantity(std::string prod);

    /** Provides access to the inventory items */
    const std::unordered_map<std::string, Product>& getInvItems() const;
};

#endif //HASHING_INVENTORY_H
