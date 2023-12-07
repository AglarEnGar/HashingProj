#include "CartItem.h"

CartItem::CartItem(){
    (*this).prev = nullptr;
    (*this).next = nullptr;
}
CartItem::~CartItem() = default;
CartItem* CartItem::getPrev(){
    return (*this).prev;
}

CartItem* CartItem::getNext(){
    return (*this).next;
}
Product CartItem::getItem(){
    return (*this).cartItem;
}

int CartItem::getQuantity(){
    return (*this).quantity;
}

void CartItem::setPrev(CartItem* newPrev){
    (*this).prev = newPrev;
}

void CartItem::setNext(CartItem* newNext){
    (*this).next = newNext;
}

void CartItem::setItem(Product newItem){
    (*this).cartItem = newItem;
}

void CartItem::setQuantity(int newQuantity){
    (*this).quantity = newQuantity;
}

std::string CartItem::toString() const {
    std::ostringstream oss;
    oss << Product::toString() << ", "
        << "Quantity: " << quantity;
    return oss.str();
}