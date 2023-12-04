#include <iostream>
#include <hash_map>
#include <string>


struct hList
{
    std::string word;
    std::size_t index;
};

int main() {

    std::cout << "Welcome to our store: Enter a number off the menu to select a choice";
    std::cout << "(1) View items in our inventory\n";
    std::cout << "(2) Add an item to your cart\n";
    std::cout << "(3) Remove an item to your cart\n";
    std::cout << "(4) Checkout an item from your cart\n";

    return 0;
}
