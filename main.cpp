#include <iostream>
#include <hash_map>
#include <string>
#include "main.h"

using namespace std;

std::string Product::getDescription() const{ return (*this).description; }
int Product::getProductId() const { return (*this).productId; }
std::string Product::getProductName() const{  return (*this).productName; }
double Product::getProductPrice() const { return (*this).productPrice; }

void Product::setDescription(std::string str) { (*this).description = str; }
void Product::setProductId(int id) { (*this).productId = id; }
void Product::setProductName(std::string str) { (*this).productName = str; }
void Product::setProductPrice(double price) { (*this).productPrice = price; }








int main() {
    std::string word = "ooga";
    std::size_t hash_booger = std::hash<std::string>{}(word);

    std::cout << "Lol hi";

    return 0;
}

