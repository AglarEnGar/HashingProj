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
//The search function for inventory
//Uses the name of the product you want to find, as all the products are indexes by their names.
Product * Inventory::getFromName(std::string name) const
{
    auto search = in1->find(name);
    if(search != in1->end())
    {
        std::cout << "Found Product " << search->second.getProductName() << std::endl;
        return &search->second;
    }
    else
        std::cout << "ERROR! Could not find your Product." << std::endl;
    return nullptr;

}
void Inventory::delFromName(std::string name)
{
    in1->erase(in1->find(name));
}
//insertion is the only way to add items since this is an unordered list. So it doesnt matter if an item is at the "front" or "back" of the list.
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
//Should work because items with the same name, or same string key get put into the same bucket.
//however it looks like only some of those end up in the buckets, and most repetitions get deleted...
unsigned int Inventory::itemQuantity(std::string prod)
{
    auto bucket = in1->bucket(prod);
    return in1->bucket_size(bucket);
}