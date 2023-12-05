#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H

struct Product{
private:
    int productId = 0;
    std::string productName;
    double productPrice;
    std::string description;

public:
    Product();
    int getProductId();
    double getProductPrice();
    std::string getProductName();
    std::string getDescription();

    void setProductName(std::string newName);
    void setDescription(std::string newDescription);
    void setProductId(int id);
    void setProductPrice(double price);
}; 

#endif