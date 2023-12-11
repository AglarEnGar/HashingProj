
//
// Created by lucaj on 12/5/2023.
//
/*
 在您的 OOP 购物项目中，如果产品是按名称存储（如 std::unordered_map<std::string, Product>），并且您希望跟踪相同产品的不同实例（例如两个相同的罐装可乐），您可能需要考虑一种不同的方法。使用 unordered_map 以产品名称为键，意味着同名的产品会覆盖彼此，只保留一个实例。

如果您想要跟踪每个单独的产品实例，即使它们是相同的产品，您可能需要调整数据结构。例如，您可以使用 std::unordered_map<std::string, std::vector<Product>>，这样，相同名称的每个产品都可以作为一个单独的 Product 对象存储在向量中。这样，每个相同的产品都有自己的实例，但它们都归类在同一个名称下。
 *
 * */
#ifndef HASHING_INVENTORY_H
#define HASHING_INVENTORY_H

#include "Product.h"
#include <hash_map>
#include <unordered_map>

class Inventory{
private:
    std::unordered_map<std::string, Product> *inv1;

public:
    Inventory();
    ~Inventory();
    Product * getFromName(std::string name) const;
    void delFromName(std::string name);
    void insert(const Product &p);
    void printall();
    unsigned int size() const;
    unsigned int itemQuantity(std::string prod);
    const std::unordered_map<std::string, Product>& getInvItems() const;
};


#endif //HASHING_INVENTORY_H
