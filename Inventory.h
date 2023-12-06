//
// Created by lucaj on 12/5/2023.
//

#ifndef HASHING_INVENTORY_H
#define HASHING_INVENTORY_H

#include "Product.h"
#include <hash_map>
#include <unordered_map>

class Inventory{
private:
    std::unordered_map<std::string, Product> *in1;

public:
    Inventory();
    ~Inventory();
    Product * getFromName(std::string name) const;
    void delFromName(std::string name);
    void insert(const Product &p);
    void printall();
    unsigned int size() const;
    unsigned int itemQuantity(std::string prod);
};


#endif //HASHING_INVENTORY_H
