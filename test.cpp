#include "test.h"
#include "CartItem.h"
#include "Cart.h"
#include <iostream>

void testCartItem(){
    CartItem* itemPtr = new CartItem;
    if ((*itemPtr).getNext() == NULL){
        std::cout << "# 2. Next is NULL\n";
    }
	else {
        std::cout << "\t\tERROR: # 2. Next is not NULL\n";
    }
	if ((*itemPtr).getPrev() == NULL){ 	
        std::cout << "# 3. Prev is NULL\n";
    }
	else {
        std::cout << "\t\tERROR: # 3. Prev is not NULL";
    }
    delete itemPtr;
    itemPtr = nullptr;
}

void testCart(){
    Cart* cartPtr = new Cart;
    if ((*cartPtr).getHead() == NULL){
        std::cout << "Head is NULL\n";
    }
	else {
        std::cout << "\t\tERROR: Head is not NULL\n";
    }
	if ((*cartPtr).getTail() == NULL){ 	
        std::cout << "Tail is NULL\n";
    }
	else {
        std::cout << "\t\tERROR: Tail is not NULL";
    }
    delete cartPtr;
    cartPtr = nullptr;
}

void getMenu(){
    int menuItem;
    std::cout << "Test options menu: \n";
    std::cout << "(1) Test Cart\n";
    std::cout << "(2) Test CartItem\n";
    std::cout << "Enter 1, 2, or 0 to exit.\n";
    while(menuItem != 0){
        std::cin >> menuItem;
        if(menuItem == 1){
            testCart();
        } else if(menuItem == 2){
            testCartItem();
        }
    }
    std::cout << "Goodbye\n";
}