/** 
 * @file store.h
 * @brief Defines the store class for the OOP Shopping System.
 * 
 * This file provides the declaration of the store class. The store class is the main interface
 * for the shopping system, managing both customer and administrative tasks. It handles menu options,
 * prompting tasks, loading and outputting inventory and cart data to files.
 * 
 * @author Luca, Canxin, Juan
 * @date 12/5/2023
 */

#ifndef HASHING_STORE_H
#define HASHING_STORE_H

#include "Inventory.h"
#include "Cart.h"

#define MAIN_INV_FILE "inventory_list.csv"
#define MAIN_OUT_FILE "inventory_update.csv"

class store {
private:
    const std::string mainInvFile = "inventory_list.csv"; /**< File name for main inventory */
    const std::string mainOutFile = "inventory_update.csv"; /**< File name for inventory output */
    int max_menu_option = 10; /**< Maximum number of menu options */
    int max_inventory_file = 5; /**< Maximum number of inventory files */

public:
    /** Default constructor */
    store();

    /** Destructor */
    ~store();

    /** Displays menu options for administrators */
    int menuOptionsAdm();

    /** Displays menu options for customers */
    int menuOptionsCus();

    /** Prompts tasks for customers */
    void promptTasksCus(Inventory * inv, Cart * maincart1);

    /** Prompts tasks for administrators */
    void promptTasksAdm(Inventory * inv, Cart * maincart1);

    /** Loads inventory data from a file */
    Inventory *loadFileIntoInv(std::string file = MAIN_INV_FILE);

    /** Outputs cart data into a file */
    void outputCartIntoFile(const std::string& ofileCart, Cart *cart);

    /** Outputs inventory data into a file */
    void outputInvIntoFile(const std::string& oofile = MAIN_OUT_FILE, const Inventory* inv = nullptr);
};

#endif //HASHING_STORE_H
