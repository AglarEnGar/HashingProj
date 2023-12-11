#include <string>
#ifndef HASHING_MYHASHING_H
#define HASHING_MYHASHING_H

struct Product{
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

class Inventory{
    
};

class Store{
private:
    std::string menu;
    Inventory* storeInventory;
public:
    /// prints menu
    void getMenu();
};

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

    void setHead(CartItem* newHead);
    void setTail(CartItem* newTail);

    void push_back(CartItem* newItem);
};

#endif //HASHING_MYHASHING_H
