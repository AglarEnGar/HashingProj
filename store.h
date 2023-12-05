//
// Created by lucaj on 12/5/2023.
//

#ifndef HASHING_STORE_H
#define HASHING_STORE_H
#include "Inventory.h"

class store {
private:
    std::string mainInvFile = "inventory_list.csv";
    std::string mainOutFile = "inventory_update.csv";
    int max_menu_option = 10;
    int max_inventory_file = 5;
public:
    store();
    ~store();
    int menuOptionsAdm();
    int menuOptionsCus();
    void promptTasksCus(Inventory * inv);
    void promptTasksAdm(Inventory * inv);
    Inventory * loadFileintoInv(std::string file);
    void loadItemsFromInv(Product c1);
    void outputCartintoFile(std::string ofile);
    void outputInvintoFile(std::string oofile);
    void insertionSortCart();
    void mergeSortCart();
    void quicksortCart();
};


#endif //HASHING_STORE_H