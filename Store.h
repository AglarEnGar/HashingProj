#include <string>
#ifndef STORE_H
#define STORE_H
#include "Cart.h"
#include "Inventory.h"

class Store{
private:
    Cart* userCart;
    Inventory* storeInventory;
public:
    Store();
    /// prints menu
    void getMenu();
};

#endif