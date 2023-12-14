/** 
 * @file main.cpp
 * @brief Main entry point for the OOP Shopping System.
 * 
 * This file contains the main function which serves as the entry point for the shopping system.
 * It initializes the store, cart, and inventory objects, and manages the flow of the program
 * by calling appropriate functions for customer tasks. The file handles the primary interaction
 * between the store's inventory, shopping cart, and user input.
 * 
 * @author Luca, Canxin, Juan
 * @date 12/5/2023
 */

#include <string>
#include <fstream>

#include "Cart.h"
#include "Inventory.h"
#include "store.h"

#define DEFAULT_INVENTORY "inventory_list.csv"  /**< Default inventory file name */
#define DEFAULT_OUTPUT_FILE "inventory_update.csv" /**< Default output file name */

using namespace std;

/** Main function of the application */
int main() {
    store prompter;          // Create a store object
    auto *car = new Cart;    // Initialize a new cart object
    auto *inv = prompter.loadFileIntoInv(DEFAULT_INVENTORY); // Load inventory from file

    // Start customer tasks
    prompter.promptTasksCus(inv, car);

    // Uncomment the line below to start administrative tasks
    // prompter.promptTasksAdm(inv, car);

    return 0; // Exit the program
}
