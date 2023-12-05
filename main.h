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

    bool operator==(const Product& other) const
    {
        return (productPrice == other.getProductPrice() &&
                productName == other.getProductName() &&
                productId == other.getProductId() &&
                description == other.getDescription());
    }
};
Product::Product()
{
    (*this).productId =0;
    (*this).productName = "";
    (*this).productPrice = 0.0;
    (*this).description = "Lorem Ipsum";

}
Product::~Product()
= default;

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
//
//};

class Inventory{
private:
    std::unordered_map<std::string, Product> in1;

public:
    Inventory();
    ~Inventory();
    Product getFromName(std::string name) const;
    void delFromName(std::string name);
    void insert(const Product &p);
    void printall();
    unsigned int size() const;
};

Inventory::Inventory()
= default;

Inventory::~Inventory()
{
    std::destroy((*this).in1.begin(), (*this).in1.end());
}

Product Inventory::getFromName(std::string name) const
{
    auto search = in1.find(name);
    return search->second;
}

void Inventory::delFromName(std::string name)
{
    in1.erase(in1.find(name));
}

void Inventory::insert(const Product &p)
{
    in1.insert({p.getProductName(), p});
}

void Inventory::printall()
{
    for (auto & it1 : in1)
    {
        it1.second.printProduct();

    }
}

unsigned int Inventory::size() const
{
    return (*this).in1.size();
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
    int length();

    void setHead(CartItem* newHead);
    void setTail(CartItem* newTail);

    void push_back(CartItem* newItem);
};

class store {
private:
    std::string mainInvFile = "inventory_list.csv";
    std::string mainOutFile = "inventory_update.csv";
public:
    store();
    ~store();
    int menuOptions();

    Inventory * loadFileintoInv(std::string file);
    void loadItemsFromInv(Product c1);
    void outputCartintoFile(std::string ofile);
    void outputInvintoFile(std::string oofile);
    void insertionSortCart();
    void mergeSortCart();
    void quicksortCart();
};

store::store() = default;
store::~store() = default;



#endif //HASHING_MYHASHING_H
