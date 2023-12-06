#include "Store.h"
#include <iostream>
#include <string>

Store::Store(){
    (*this).storeInventory = nullptr;
    (*this).userCart = nullptr;
}

void Store::getMenu(){
    std::cout << "Welcome to our store: Enter a number off the menu to select a choice";
    std::cout << "(1) View items in our inventory\n";
    std::cout << "(2) Add an item to your cart\n";
    std::cout << "(3) Remove an item to your cart\n";
    std::cout << "(4) Checkout an item from your cart\n";
}