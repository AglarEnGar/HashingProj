//
// Created by lucaj on 12/5/2023.
//
#include "store.h"

#include <regex>
#include <fstream>



store::store() = default;
store::~store() = default;

enum ActionsAdmin {QUITI, TOTAL_ITEM_COUNT_INV, ITEM_COUNT_INV, PRINT_TO_SCREEN_INV, REMOVE_PRODUCT_INV, ADD_PRODUCT_INV, LOAD_INV_FILE, PRINT_INV_FILE, SWITCH_TO_CUST};

enum ActionsCustomer {QUITC, TOTAL_ITEM_COUNT_CART, ITEM_COUNT_CART, CARTITEM_BACK_TO_INV, ADD_CARTITEM_FROM_INV, PRINT_CART, CHECKOUT, SELECTION_SORT_CART, NEW_CART, MERGE_CARTS,
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
        std::cout << "  (" << PRINT_CART << ") View your cart's Items\n";
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
Product * findingPrompts(int option, Inventory * inven, Cart * car);
double checkout(Cart * croom);
void addProducttoCart(Product *p, Inventory* ini, Cart * cars);
void removeProductCart(std::string nem1, Inventory* in1, Cart * car1);
void store::promptTasksCus(Inventory * inv, Cart * maincart1)
{
    int choice = 0;
    while(true)
    {
        choice = menuOptionsCus();
        switch (choice)
        {
            case TOTAL_ITEM_COUNT_CART:
                std::cout << "There are " << maincart1->size() << " items in your shopping cart." << std::endl;
                break;
            case ITEM_COUNT_CART:
                std::cout << "Coming soon! " << std::endl;
                break;
            case CARTITEM_BACK_TO_INV:
                findingPrompts(4, inv, maincart1);
                break;
            case ADD_CARTITEM_FROM_INV:
                findingPrompts(3, inv, maincart1);
                break;
            case PRINT_CART:
                std::cout << "----------------------------------SHOPPING CART----------------------------------" << std::endl;
                maincart1->printForward();
                break;
            case CHECKOUT:
                std::cout << "Your total is $";
                printf("%.2f", checkout(maincart1));
                std::cout << std::endl << "We accept Visa, Venmo and Mastercard.\n";
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
                promptTasksAdm(inv, maincart1);
                return;
            default:
                std::cout << "Thank you! Bye!" << std::endl;
                delete inv;
                return;
        }
    }

}
void store::promptTasksAdm(Inventory * inv, Cart * maincart2)
{
    int choice = 0;
    std::string input;
    while(true)
    {
        choice = menuOptionsAdm();
        switch (choice)
        {
            case TOTAL_ITEM_COUNT_INV:
                std::cout << "There are " << inv->size() << "items in the inventory." << std::endl;
                break;
            case ITEM_COUNT_INV:
                findingPrompts(1, inv, maincart2);
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
                promptTasksCus(inv, maincart2);
                return;
            default:
                std::cout << "Thank you! Bye!" << std::endl;
                delete inv;
                return;
        }
    }
}
CartItem * findIteminCart(Cart * c, std::string nam)
{
    CartItem* current = c->getHead();
    while (current != nullptr)
    {
        CartItem *next = current->getNext();
        if((*current).getItem().getProductName() == nam)
        {
            return current;
        }
        current = next;
    }
    return nullptr;
}
void addProducttoCart(Product *p, Inventory* ini, Cart * cars)
{
    std::cout << "entered function\n";
    auto *c1 = new CartItem;
    c1->setItem(*p);
    std::cout << "item successfully made\n";
    ini->delFromName(p->getProductName());
    std::cout << "inventory product deleted\n";
    cars->push_back(c1);
}
double checkout(Cart * croom)
{
    double cost = 0.0;
    for(CartItem * it = croom->getHead(); it != croom->getTail(); it = it->getNext())
    {
        cost += it->getItem().getProductPrice();
    }
    return cost;
}
void removeProductCart(std::string nem1, Inventory* in1, Cart * car1)
{
    CartItem * c1 = findIteminCart(car1, nem1);
    Product p1 = c1->getItem();
    in1->insert(p1);
    car1->removeItem(c1);
}
Product * findingPrompts(int option, Inventory * inven, Cart * car)
{
    Product * p;
    std::string in;
    std::cout << "What item do you want to find ";
    bool b = true;

    switch(option)
    {
        case 1:
            std::cout << "to count?" << std::endl;
            std::getline(std::cin, in);
            std::getline(std::cin, in);
            std::cout << "Your word was '" << in << "'." << std::endl;
            p = inven->getFromName(in);
            if(!p->getProductName().empty())
            {
                std::cout << "There are " << inven->itemQuantity(in) << " units of that item." << std::endl;
            }
            return p;
        case 2:
            std::cout << "to remove?" << std::endl;
            std::getline(std::cin, in);
            std::getline(std::cin, in);
            std::cout << "Your word was '" << in << "'." << std::endl;
            p = inven->getFromName(in);
            if(!p->getProductName().empty())
            {
                inven->delFromName(in);
                std::cout << "Product removed\n";
            }
            return p;
        case 3:
            std::cout <<"to add to your cart?\n";
            while(b) {
                std::cout << "----------------------------------STORE INVENTORY----------------------------------" << std::endl;
                inven->printall();
                std::cout << "\nPlease type the name of the item you wish to add." << std::endl;

                //You need to do this for some reason because it ignores the getline on the first pass
                std::getline(std::cin, in);
                std::getline(std::cin, in);

                p = inven->getFromName(in);
                if(p != nullptr)
                {
                    addProducttoCart(p, inven, car);
                    std::cout << "\"" << in << "\"" << " Added!" << std::endl;

                    std::cout << "Add another item? y/n\n";
                    in = "";
                    while( in.empty() && std::cin >> in )
                    {
                        if (in == "y")
                        {
                            b = true;
                        }
                        else if(in == "n")
                        {
                            b = false;
                        }
                        else {
                            std::cout << "Error, invalid command. please type \"y\" or \"n\". \n";
                            in = "";
                        }
                    }
                }
            }
            return nullptr;
        case 4:
            std::cout <<"to remove from your cart?\n";
            while(b) {
                std::cout << "----------------------------------SHOPPING CART----------------------------------" << std::endl;
                car->printForward();
                std::cout << "\nPlease type the name of the item you wish to remove.\n";

                std::getline(std::cin, in);
                std::getline(std::cin, in);

                if(findIteminCart(car, in) != nullptr)
                {
                    removeProductCart(in, inven, car);
                    std::cout << "\"" << in << "\"" << " Removed!" << std::endl;
                    if(car->size() != 0)
                    {
                        std::cout << "Remove another item? y/n\n";
                        in = "";
                        while( in.empty() && std::cin >> in )
                        {
                            if (in == "y")
                            {
                                b = true;
                            }
                            else if(in == "n")
                            {
                                b = false;
                            }
                            else {
                                std::cout << "Error, invalid command. please type \"y\" or \"n\". \n";
                                in = "";
                            }
                        }
                    }
                    else {
                        std::cout << "Cart is now empty!" << std::endl;
                        return nullptr;
                    }
                } else {
                    std::cout << "Could not find that item in your cart!\n";
                }
            }

        default:
            return nullptr;
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

//void store::outputCartintoFile(const std::string& ofile, Cart *cart) {
//    std::ofstream outFile(ofile);
//    if (!outFile.is_open()) {
//        std::cerr << "Unable to open file: " << ofile << std::endl;
//        return;
//    }
//
//    CartItem* currentItem = cart->getHead();
//    while (currentItem != nullptr) {
//        // Assuming CartItem has a method to get a string representation of itself
//        outFile << currentItem->toString() << std::endl;
//        currentItem = currentItem->getNext();
//    }
//
//    outFile.close();
//}

void store::outputCartintoFile(const std::string& ofile, Cart *cart) {
    std::ofstream outFile(ofile);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file: " << ofile << std::endl;
        return;
    }

    CartItem* currentItem = cart->getHead();
    while (currentItem != nullptr) {
        // Constructing a CSV line for each CartItem.
        // Replace getProductName(), getQuantity(), getPrice() with actual getters from CartItem.
        outFile << currentItem->getProductName() << ","
                << currentItem->getQuantity() << ","
                << currentItem->getProductPrice() << std::endl;

        currentItem = currentItem->getNext();
    }

    outFile.close();
}