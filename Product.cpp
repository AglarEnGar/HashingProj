#include "Product.h"

Product::Product(){
    (*this).description = "n/a";
    (*this).productId =  0;
    (*this).productName = "n/a";
    (*this).productPrice = 0;
}

int Product::getProductId(){
    return (*this).productId;
}

double Product::getProductPrice(){
    return (*this).productPrice;
}
    
std::string Product::getProductName(){
    return (*this).productName;
}

std::string Product::getDescription(){
    return (*this).description;
}

void Product::setProductName(std::string newName){
    (*this).productName = newName;
}
    
void Product::setDescription(std::string newDescription){
    (*this).description = newDescription;
}
    
void Product::setProductId(int id){
    (*this).productId = id;
}

void Product::setProductPrice(double price){
    (*this).productPrice = price;
}