#include "Cart.h"

Cart::Cart(){
    (*this).head = nullptr;
    (*this).tail = nullptr;
}

Cart::Cart(CartItem* newHead, CartItem* newTail){
    (*this).head = newHead;
    (*this).tail = newTail;
}

CartItem* Cart::getHead(){
    return (*this).head;
}

CartItem* Cart::getTail(){
    return (*this).tail;
}

int Cart::size(){
    return (*this).sizeCart;
}

void Cart::setHead(CartItem* newHead){
    (*this).head = newHead;
}

void Cart::setTail(CartItem* newTail){
    (*this).tail = newTail;
}

void Cart::push_back(CartItem* newItem){
    if((*this).getHead() == nullptr){
        (*this).setHead(newItem);
    } else {
        CartItem* temp = (*this).getHead();
        while(temp->getNext() != nullptr){
            temp = temp -> getNext();
        }
        temp -> setNext(newItem);
    }

    (*this).sizeCart++;
}

CartItem* Cart::linearSearch(){
    std::string itemName;
    std::cout << "Enter a word to find: ";
    std::cin >> itemName;
    std::cout << "\nYour word was \'" << itemName << "\'.\n";
    CartItem* ptrCurr = (*this).getHead();
    for(int i=0; i<(*this).size(); i++){
        if(ptrCurr -> getItem() . getProductName() == itemName){
            if(ptrCurr != (*this).getHead()){
                std::cout << "The previous word would be \'" << ptrCurr->getPrev()->getItem().getProductName() << "\'.\n";
            }
            if(ptrCurr != (*this).getTail()){
                std::cout << "The next word would be \'" << ptrCurr->getNext()->getItem().getProductName() << "\'.\n";
            }
            return ptrCurr;
        }
        ptrCurr = ptrCurr -> getNext();
    }
    std::cout << "We did not find your word.\n";
    return nullptr;
}

void swapWords(CartItem* smallest, CartItem* ptrNext){
    CartItem* smallestPrev = smallest->getPrev();
    CartItem* smallestNext = smallest->getNext();
    CartItem* nextPrev = ptrNext->getPrev();
    CartItem* nextNext = ptrNext->getNext();

    smallest->setPrev(nextPrev);
    smallest->setNext(nextNext);
    ptrNext->setPrev(smallestPrev);
    ptrNext->setNext(smallestNext);

    smallestPrev->setNext(ptrNext);
    smallestNext->setPrev(ptrNext);

    nextPrev->setNext(smallest);
    nextNext->setPrev(smallest);
}

int Cart::selectionSort() {
    CartItem* ptrCurr = (*this).head;
    CartItem* smallest;
    CartItem* ptrNext;
    int swaps;
    std::cout << "sorting...\n";
    for(int i=0; i<(*this).size(); i++){
        smallest = ptrCurr;
        ptrNext = ptrCurr->getNext();
        for(int j=i+1; j<(*this).size(); j++){
            if(ptrNext->getItem().getProductName() > smallest->getItem().getProductName()){
                smallest = ptrNext;
                ptrNext = ptrNext -> getNext();
            }
        }
        swapWords(smallest, ptrNext);
        if(smallest->getItem().getProductName() != ptrNext->getItem().getProductName()){
            swaps++;
        }
        ptrCurr = ptrCurr -> getNext();
    }
    std::cout << "        " << swaps << " swaps done by Selection Sort.\n";
    std::cout << "                           ...Done!\n";
    return swaps;
}