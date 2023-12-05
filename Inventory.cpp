//
// Created by lucaj on 12/5/2023.
//
#include "Inventory.h"

Inventory::Inventory()
{
    in1 = new std::unordered_map<std::string, Product>;

}
Inventory::~Inventory()
{
    delete in1;
}

Product Inventory::getFromName(std::string name) const
{
    auto search = in1->find(name);
    if(search != in1->end())
    {
        std::cout << "Found Product " << search->second.getProductName() << std::endl;
        return search->second;
    }
    else
        std::cout << "ERROR! Could not find your Product." << std::endl;
    Product p;
    return p;

}

void Inventory::delFromName(std::string name)
{
    in1->erase(in1->find(name));
}

void Inventory::insert(const Product &p)
{
    in1->insert({p.getProductName(), p});
}

void Inventory::printall()
{
    for (auto & it1 : *in1)
    {
        it1.second.printProduct();

    }
}
unsigned int Inventory::size() const
{
    return (*this).in1->size();
}

unsigned int Inventory::itemQuantity(std::string prod)
{
    auto bucket = in1->bucket(prod);
    return in1->bucket_size(bucket);
}