/** 
 * @file Product.h
 * @brief Defines the Product structure for the OOP Shopping System.
 * 
 * Provides the declaration of the Product structure including its member variables,
 * constructors, destructors, getters, setters, utility methods, and operator overloading.
 * This structure is used to represent a product in the shopping system, encapsulating
 * details like product ID, name, price, and description.
 * 
 * @author Luca; Canxin; Juan
 * @date 12/5/2023
 */

#ifndef HASHING_PRODUCT_H
#define HASHING_PRODUCT_H

#include <iostream>
#include <sstream>
#include <string>

struct Product {
private:
    int productId;        /**< Unique identifier for the product */
    std::string productName;  /**< Name of the product */
    double productPrice;      /**< Price of the product */
    std::string description;  /**< Description of the product */

public:
    /** Default constructor */
    Product();

    /** Destructor */
    ~Product();

    /** Returns the product ID */
    int getProductId() const;

    /** Returns the product price */
    double getProductPrice() const;

    /** Returns the product name */
    std::string getProductName() const;

    /** Returns the product description */
    std::string getDescription() const;

    /** Sets the product name */
    void setProductName(std::string str);

    /** Sets the product description */
    void setDescription(std::string str);

    /** Sets the product ID */
    void setProductId(int id);

    /** Sets the product price */
    void setProductPrice(double price);

    /** Prints product details */
    void printProduct();

    /**
     * Generates a string for menu item display.
     * @return String representation of the product for menu items.
     * Note: Requires appending 'endl' when printed.
     */
    [[nodiscard]] virtual std::string toMenuItemString() const;

    /**
     * Generates a CSV format string for the product.
     * @return CSV formatted string of the product.
     * Format: 'Product ID,Product Name,Price,Description'
     * Note: 'endl' is needed after printing.
     */
    [[nodiscard]] virtual std::string toCSVString() const;

    /**
     * Compares two products for equality based on their attributes.
     * @param other The other product to compare with.
     * @return True if the products are equal, false otherwise.
     */
    bool operator==(const Product& other) const;
};

#endif // HASHING_PRODUCT_H
