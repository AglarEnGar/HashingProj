#include "Inventory.h"
#include <iostream>
#include <string>

Inventory::Inventory(){
    (*this).items = 0;
}

void Inventory::sayHi(){
    std::cout << "hi";
}