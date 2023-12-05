//
// Created by lucaj on 11/29/2023.
//
#include <string>
#include <hash_map>
#include <hash_set>
#include <unordered_map>


#ifndef HASHING_MYHASHING_H
#define HASHING_MYHASHING_H

struct Product{
private:
    int productId = 0;
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

    bool operator==(const Product& other) const
    {
        return (productPrice == other.getProductPrice() &&
                productName == other.getProductName() &&
                productId == other.getProductId() &&
                description == other.getDescription());
    }
};

template <>
struct std::hash<Product>
{
    std::size_t operator()(const Product &p) const noexcept
    {
        std::size_t build = 17;
        build = build * 31 + std::hash<std::string>()( p.getDescription() );
        build = build * 31 + std::hash<std::string>()( p.getProductName() );
        build = build * 31 + std::hash<int>()( p.getProductId() );
        build = build * 31 + std::hash<double>()( p.getProductPrice() );
        return build;
    }

};

class Inventory{
private:
    std::unordered_map<int, Product> in1;
    int size = 0;

public:
    Inventory();
    ~Inventory();
    Product getFromId(int id);
    void setFromId(int id);
    void insert(Product p);

};

Inventory::Inventory()
= default;

Inventory::~Inventory()
{
    std::destroy((*this).in1.begin(), (*this).in1.end());
}

void Inventory::insert(Product p)
{
    in1.insert({p.getProductId(), p});
}


class CartItem {
private:
    Product cartItem;
    CartItem* prev;
    CartItem* next;
    int quantity;
public:
    CartItem* getPrev();
    CartItem* getNext();
    Product getItem();
    int getQuantity();

    void setPrev(CartItem* newPrev);
    void setNext(CartItem* newNext);
    void setItem(Product newItem);
    void setQuantity(int newQuantity);
};

class Cart {
private:
    CartItem* head;
    CartItem* tail;
    int size = 0;
public:
    CartItem* getHead();
    CartItem* getTail();
    int size();

    void setHead(CartItem* newHead);
    void setTail(CartItem* newTail);

    void push_back(CartItem* newItem);
};

#endif //HASHING_MYHASHING_H
