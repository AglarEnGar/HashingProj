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

void Cart::printForward()
{
    CartItem * temp = (*this).head;

    while (temp != nullptr)
    {
        temp->getItem().printProduct();
        temp = temp->getNext();
    }
}

CartItem* Cart::removeItem(CartItem *item)
{
    CartItem * next = item->getNext();
    CartItem * prev = item->getPrev();
    if(item == (*this).head && item == (*this).tail)
    {
        delete item;
        (*this).head = nullptr;
        (*this).tail = nullptr;
        (*this).sizeCart = 0;
        return nullptr;
    }
    else if (item == (*this).head)
    {
        delete (*this).head;
        (*this).sizeCart--;
        (*this).head = next;
        (*this).head->setPrev(nullptr);
        return next;
    }
    else if (item == (*this).tail)
    {
        delete (*this).tail;
        (*this).sizeCart--;
        (*this).tail = prev;
        (*this).tail->setNext(nullptr);
        return nullptr;
    }
    else
    {
        prev->setNext(next);
        next->setPrev(prev);
        (*this).sizeCart--;
        delete item;
    }
    return next;

}


void Cart::push_back(CartItem* newItem){
    if((*this).head == nullptr)
    {
        (*this).head = newItem;
        (*this).tail = newItem;
        sizeCart++;
        return;
    }
    newItem->setPrev((*this).tail);
    (*this).tail->setNext(newItem);
    (*this).tail = newItem;
    sizeCart++;
}



CartItem* Cart::split(CartItem* head) {
  CartItem *fast = head, *slow = head;
  while (fast->getNext() && fast->getNext()->getNext()) {
    slow = slow->getNext();
    fast = fast->getNext()->getNext();
  }
  CartItem* temp = slow->getNext();
  slow->setNext(nullptr);
  return temp;
}
/** sort by product price */
CartItem* Cart::sortedMerge(CartItem* a, CartItem* b) {
  if (!a) return b;
  if (!b) return a;
  // sort by price
  if (a->getProductPrice() <= b->getProductPrice()) {
    a->setNext(sortedMerge(a->getNext(), b));
    a->getNext()->setPrev(a);
    a->setPrev(nullptr);
    return a;
  } else {
    b->setNext(sortedMerge(a, b->getNext()));
    b->getNext()->setPrev(b);
    b->setPrev(nullptr);
    return b;
  }
}
CartItem* Cart::mergeSort(CartItem* head) {
  if (!head || !head->getNext()) {
    return head;
  }
  CartItem* second = split(head);
  // Recursive split
  head = mergeSort(head);
  second = mergeSort(second);
  // Merge sorted linked list
  return sortedMerge(head, second);
}
// final public interface
void Cart::mergeSortCart() {
  head = mergeSort(head);
  // reset tail
  CartItem* temp = head;
  while (temp && temp->getNext()) {
    temp = temp->getNext();
  }
  tail = temp;
}
