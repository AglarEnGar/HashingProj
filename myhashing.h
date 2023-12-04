//
// Created by lucaj on 11/29/2023.
//

#ifndef HASHING_MYHASHING_H
#define HASHING_MYHASHING_H

class Product {
private:
    int productId = 0;
    std::string productName;
    double productPrice;
    std::string description;

public:
    int getProductId();
    double getProductPrice();
    std::string getProductName();
    std::string getDescription();

    void setProductName(std::string);
    void setDescription(std::string);
    void setProductId(int id);
    void setProductPrice(double price);
};

class Inventory {

};

class CartItem {

};

class Cart {

};

#endif //HASHING_MYHASHING_H
