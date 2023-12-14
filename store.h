//
// Created by lucaj on 12/5/2023.
//

#ifndef HASHING_STORE_H
#define HASHING_STORE_H
#include "Inventory.h"
#include "Cart.h"

#define MAIN_INV_FILE "inventory_list.csv"
#define MAIN_OUT_FILE "inventory_update.csv"

class store {
private:
    const std::string mainInvFile = "inventory_list.csv";
    const std::string mainOutFile = "inventory_update.csv";
    int max_menu_option = 10;
    int max_inventory_file = 5;

public:
    store();
    ~store();
    int menuOptionsAdm();
    int menuOptionsCus();
    void promptTasksCus(Inventory * inv, Cart * maincart1);
    void promptTasksAdm(Inventory * inv, Cart * maincart1);

    Inventory *loadFileIntoInv(std::string file = MAIN_INV_FILE);
    /** "Product ID,Product Name,Price,Description" */
    void outputCartIntoFile(const std::string&ofileCart,Cart *cart);
    void outputInvIntoFile(const std::string& oofile = MAIN_OUT_FILE, const Inventory* inv = nullptr);

    //void outputInvintoFile(std::string oofile);
    //void loadAnItemFromInv(const Product& product);
    // void loadItemsFromInv(const std::vector<Product>& products);
};


#endif //HASHING_STORE_H
