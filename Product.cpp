//
// Created by lucaj on 12/5/2023.
//


#include "Product.h"

Product::Product()
{
    (*this).productId =0;
    (*this).productName = "";
    (*this).productPrice = 0.0;
    (*this).description = "Lorem Ipsum";

}
Product::~Product()
{
    (*this).productId =0;
    (*this).productName = "";
    (*this).productPrice = 0.0;
    (*this).description = "";
}



std::string Product::getDescription() const{ return (*this).description; }
int Product::getProductId() const { return (*this).productId; }
std::string Product::getProductName() const{  return (*this).productName; }
double Product::getProductPrice() const { return (*this).productPrice; }

void Product::setDescription(std::string str1) { (*this).description = str1; }
void Product::setProductId(int id) { (*this).productId = id; }
void Product::setProductName(std::string str2) { (*this).productName = str2; }
void Product::setProductPrice(double price) { (*this).productPrice = price; }

void Product::printProduct()
{
    std::cout   << "\"" << (*this).productName << "\"" << " | "
                << "Price: $" << (*this).productPrice << " | "
                << "Details: " << (*this).description << " | "
                << "S/N: " << (*this).productId << std::endl;
}
std::string Product::toString() const {
    std::ostringstream oss;
    oss << "Product Name: " << getProductName() << ", "
        << "Price: $" << getProductPrice() << ", "
        << "Description: " << getDescription() << ", "
        << "Product ID: " << getProductId();
    return oss.str();
}

//template <>
//struct std::hash<Product>
//{
//    std::size_t operator()(const Product &p) const noexcept
//    {
//        std::size_t build = 17;
//        build = build * 31 + std::hash<std::string>()( p.getDescription() );
//        build = build * 31 + std::hash<std::string>()( p.getProductName() );
//        build = build * 31 + std::hash<int>()( p.getProductId() );
//        build = build * 31 + std::hash<double>()( p.getProductPrice() );
//        return build;
//    }
//};


