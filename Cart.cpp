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