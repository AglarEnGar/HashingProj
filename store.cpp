//
// Created by lucaj on 12/5/2023.
//
#include "store.h"

#include <regex>
#include <fstream>



store::store() = default;
store::~store() = default;

enum ActionsAdmin {QUITI, TOTAL_ITEM_COUNT_INV, ITEM_COUNT_INV, PRINT_TO_SCREEN_INV, REMOVE_PRODUCT_INV, ADD_PRODUCT_INV, LOAD_INV_FILE, PRINT_INV_FILE, SWITCH_TO_CUST};

enum ActionsCustomer {QUITC, TOTAL_ITEM_COUNT_CART, ITEM_COUNT_CART, CARTITEM_BACK_TO_INV, ADD_CARTITEM_FROM_INV, CHECKOUT, SELECTION_SORT_CART, NEW_CART, MERGE_CARTS,
    LOAD_NEW_CART, WRITE_CART_TO_FILE, SWITCH_TO_ADMIN};


int store::menuOptionsAdm()
{
    int choice = 0;

    while(true) {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Options menu: " << std::endl;
        std::cout << "  (" << TOTAL_ITEM_COUNT_INV << ") Count - get number of Products in Inventory\n";
        std::cout << "  (" << ITEM_COUNT_INV << ") - get the number of a certain Product in Inventory\n";
        std::cout << "  (" << PRINT_TO_SCREEN_INV << ") Print the full list of items in Inventory\n";
        std::cout << "  (" << REMOVE_PRODUCT_INV << ") Find a product, and if found, remove that product from inventory\n";
        std::cout << "  (" << ADD_PRODUCT_INV << ") Add a product to Inventory\n";
        std::cout << "  (" << LOAD_INV_FILE << ") Load a new cvs file for Inventory\n";
        std::cout << "  (" << PRINT_INV_FILE << ") Print the currently managed Inventory to console\n";
        std::cout << "  (" << SWITCH_TO_CUST << ") Switch to the customer menu\n";
        std::cout << "Enter a number from " << 1 << " to " << SWITCH_TO_CUST << ", or " << QUITI << " to exit: "
                  << std::endl;

        std::cin >> choice;

        if (choice < QUITC || choice > SWITCH_TO_CUST) {
            std::cout << "Error! Input must be a number between " << 1 << " and " << SWITCH_TO_CUST << ", or " << QUITC << " to exit." << std::endl;
        } else if (choice == QUITC) {
            return QUITC;
        } else {
            return choice;
        }
    }
}
int store::menuOptionsCus()
{
    int choice = 0;

    while(true)
    {
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Options menu: " << std::endl;
        std::cout << "  (" << TOTAL_ITEM_COUNT_CART << ") Get the total number of items in your cart\n";
        std::cout << "  (" << ITEM_COUNT_CART << ") Get the number of a particular item in your cart\n";
        std::cout << "  (" << CARTITEM_BACK_TO_INV << ") Remove an Item from your cart\n";
        std::cout << "  (" << ADD_CARTITEM_FROM_INV << ") Add an Item to your cart from Inventory\n";
        std::cout << "  (" << CHECKOUT << ") Calculate the total price of all the products in your cart\n";
        std::cout << "  (" << SELECTION_SORT_CART << ") Sort your cart with the selection sort algorithm (You only sort the names)\n";
        std::cout << "  (" << NEW_CART << ") Save your current cart to a file, start in a new empty cart\n";
        std::cout << "  (" << MERGE_CARTS << ") If you have multiple Carts, you can merge them into one cart.\n";
        std::cout << "  (" << LOAD_NEW_CART << ") Loads a new cart from an inputted file name.\n";
        std::cout << "  (" << WRITE_CART_TO_FILE << ") Saves your current cart to a file.\n";
        std::cout << "  (" << SWITCH_TO_ADMIN << ") Switch to admin menu.\n";
        std::cout << "Enter a number from " << 1 << " to " << SWITCH_TO_ADMIN << ", or " << QUITC << " to exit: " << std::endl;

        std::cin >> choice;

        if(choice < QUITC || choice > SWITCH_TO_ADMIN)
        {
            std::cout << "Error! Input must be a number between " << 1 << " and " << SWITCH_TO_ADMIN << ", or " << QUITC << " to exit." << std::endl;
        } else if(choice == QUITC)
        {
            return QUITC;
        }
        else
        {
            return choice;
        }
    }
}

void store::promptTasksCus(Inventory * inv)
{
    int choice = 0;
    while(true)
    {
        choice = menuOptionsCus();
        switch (choice)
        {
            case TOTAL_ITEM_COUNT_CART:
                std::cout << "Coming soon! " << std::endl;
                break;
            case ITEM_COUNT_CART:
                std::cout << "Coming soon! " << std::endl;
                break;
            case CARTITEM_BACK_TO_INV:
                std::cout << "Coming soon! " << std::endl;
                break;
            case ADD_CARTITEM_FROM_INV:
                std::cout << "Coming soon! " << std::endl;
                break;
            case SELECTION_SORT_CART:
                std::cout << "Coming soon! " << std::endl;
                break;
            case NEW_CART:
                std::cout << "Coming soon! " << std::endl;
                break;
            case MERGE_CARTS:
                std::cout << "Coming soon! " << std::endl;
                break;
            case LOAD_NEW_CART:
                std::cout << "Coming soon! " << std::endl;
                break;
            case WRITE_CART_TO_FILE:
                std::cout << "Coming soon! " << std::endl;
                break;
            case SWITCH_TO_ADMIN:
                promptTasksAdm(inv);
                return;
            default:
                std::cout << "Thank you! Bye!" << std::endl;
                delete inv;
                return;
        }
    }

}
void store::promptTasksAdm(Inventory * inv)
{
    int choice = 0;
    while(true)
    {
        choice = menuOptionsAdm();
        switch (choice)
        {
            case TOTAL_ITEM_COUNT_INV:
                std::cout << "Coming soon! " << std::endl;
                break;
            case ITEM_COUNT_INV:
                std::cout << "Coming soon! " << std::endl;
                break;
            case PRINT_TO_SCREEN_INV:
                inv->printall();
                break;
            case REMOVE_PRODUCT_INV:
                std::cout << "Coming soon! " << std::endl;
                break;
            case ADD_PRODUCT_INV:
                std::cout << "Coming soon! " << std::endl;
                break;
            case LOAD_INV_FILE:
                std::cout << "Coming soon! " << std::endl;
                break;
            case PRINT_INV_FILE:
                std::cout << "Coming soon! " << std::endl;
                break;
            case SWITCH_TO_CUST:
                promptTasksCus(inv);
                return;
            default:
                std::cout << "Thank you! Bye!" << std::endl;
                delete inv;
                return;
        }
    }
}


const std::regex comma(",");

Inventory * store::loadFileintoInv(std::string file)
{
    auto * p = new Product;
    auto * inv = new Inventory;
    std::string line = "";
    std::ifstream input_file;
    input_file.open(file);


    if(!input_file.is_open())
    {
        std::cout << "ERROR! Cannot read chosen file " << file << ". File \"" << 1 << "\" remains open." << std::endl;
        return loadFileintoInv(mainInvFile);
    }

    while(input_file && getline(input_file, line))
    {
        std::vector<std::string> row { std::sregex_token_iterator(line.begin(),line.end(),comma,-1), std::sregex_token_iterator() };
        p->setProductId(stoi(row.at(0)));
        p->setProductName(row.at(1));
        p->setProductPrice(std::stod(row.at(2)));
        p->setDescription(row.at(3));
        inv->insert(*p);
    }
    return inv;
}