#include "test.h"


void testCartItem() {
  CartItem *itemPtr = new CartItem;
  if ((*itemPtr).getNext() == NULL) {
    std::cout << "# 2. Next is NULL\n";
  } else {
    std::cout << "\t\tERROR: # 2. Next is not NULL\n";
  }
  if ((*itemPtr).getPrev() == NULL) {
    std::cout << "# 3. Prev is NULL\n";
  } else {
    std::cout << "\t\tERROR: # 3. Prev is not NULL";
  }
  delete itemPtr;
  itemPtr = nullptr;
}

void testCart() {
  Cart *cartPtr = new Cart;
  if ((*cartPtr).getHead() == NULL) {
    std::cout << "Head is NULL\n";
  } else {
    std::cout << "\t\tERROR: Head is not NULL\n";
  }
  if ((*cartPtr).getTail() == NULL) {
    std::cout << "Tail is NULL\n";
  } else {
    std::cout << "\t\tERROR: Tail is not NULL";
  }
  delete cartPtr;
  cartPtr = nullptr;
}

void testAddRemove()
{
    Cart *cartPtr = new Cart;
    store prompter;
    Inventory *inv= prompter.loadFileIntoInv();

    for(auto it : inv->getInvItems())
    {
        prompter.addProducttoCart(&(it.second), inv, cartPtr);
    }

    std::cout << "There are " << inv->size() << " items in inventory\n";
    if(inv->size()!=0)
    {
        std::cout << "\t\tERROR: Inventory is not empty!";
        inv->printall();
    }
    if(cartPtr->size() != 30)
    {
        std::cout << "\t\tERROR: Cart didnt get all items!";
        inv->printall();
    }
}


void getMenu() {
    int menuItem;

    while (menuItem != 0) {
        std::cout << "Test options menu: \n";
        std::cout << "(1) Test Cart\n";
        std::cout << "(2) Test CartItem\n";
        std::cout << "(3) Test addProducttoCart\n";
        std::cout << "Enter 1, 2, 3 or 0 to exit.\n";
        std::cin >> menuItem;
        if (menuItem == 1) {
            testCart();
        } else if (menuItem == 2) {
            testCartItem();
        } else if( menuItem == 3) {
            testAddRemove();
        }
    }
    std::cout << "Goodbye\n";
}

