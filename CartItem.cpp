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

int CartItem::getQuantity() const{
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

std::string CartItem::toMenuItemString() const {
    std::ostringstream oss;
    oss<< Product::toMenuItemString()<< " | Quantity: " << quantity;
    return oss.str();
}
std::string CartItem::toCSVString() const {
  std::stringstream ss;
  ss << getQuantity() <<","<< Product::toCSVString();
  return ss.str();
}