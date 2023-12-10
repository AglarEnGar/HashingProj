//
// Created by lucaj on 12/5/2023.
//

#ifndef HASHING_PRODUCT_H
#define HASHING_PRODUCT_H

#include <iostream>
#include <sstream>
#include <string>

struct Product{
private:
    int productId;
    std::string productName;
    double productPrice;
    std::string description;

public:
    Product();
    ~Product();
    int getProductId() const;
    double getProductPrice() const;
    std::string getProductName() const;
    std::string getDescription() const;

    void setProductName(std::string str);
    void setDescription(std::string str);
    void setProductId(int id);
    void setProductPrice(double price);
    void printProduct();
    /** Need to append 'endl' when printed */
    std::string toMenuItemString() const;
    virtual /** Need to append "endl" if printed */
    std::string toCSVString() const;

    bool operator==(const Product& other) const
    {
        return (productPrice == other.getProductPrice() &&
                productName == other.getProductName() &&
                productId == other.getProductId() &&
                description == other.getDescription());
    }
};

#endif //HASHING_PRODUCT_H
