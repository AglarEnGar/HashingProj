#include "Cart.h"

Cart::Cart(){
    (*this).head = nullptr;
    (*this).tail = nullptr;
}

Cart::~Cart(){
      CartItem* ptrCurr = (*this).head;
      CartItem* ptrNext = (*this).head;
      while(ptrCurr != nullptr){
              ptrNext = ptrCurr->getNext();
              delete ptrCurr;
              ptrCurr = ptrNext;
      }
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



/*CartItem* split(CartItem* head) {
  CartItem *fast = head, *slow = head;
  while (fast->getNext() && fast->getNext()->getNext()) {
    slow = slow->getNext();
    fast = fast->getNext()->getNext();
  }
  CartItem* temp = slow->getNext();
  slow->setNext(nullptr);
  return temp;
}*/
/** sort by product price */
CartItem* Cart::sortedMergePrice(CartItem* a, CartItem* b) {
  if (!a) return b;
  if (!b) return a;
  // sort by price
  if (a->getProductPrice() <= b->getProductPrice()) {
    a->setNext(sortedMergePrice(a->getNext(), b));
    a->getNext()->setPrev(a);
    a->setPrev(nullptr);
    return a;
  } else {
    b->setNext(sortedMergePrice(a, b->getNext()));
    b->getNext()->setPrev(b);
    b->setPrev(nullptr);
    return b;
  }
}
CartItem* Cart::mergeSortPrice(CartItem* head) {
  if (!head || !head->getNext()) {
    return head;
  }
  CartItem* second = getMidNode2Split(head);
  // Recursive split
  head = mergeSortPrice(head);
  second = mergeSortPrice(second);
  // Merge sorted linked list
  return sortedMergePrice(head, second);
}

// final public interface
void Cart::priceMergeSortCart() {
  head = mergeSortPrice(head);
  // reset tail
  CartItem* temp = head;
  while (temp && temp->getNext()) {
    temp = temp->getNext();
  }
  tail = temp;
}

// merge sort by product name:
CartItem* Cart::getMidNode2Split(CartItem* head) {
  CartItem *fast = head, *slow = head;
  while (fast->getNext() && fast->getNext()->getNext()) {
    slow = slow->getNext();
    fast = fast->getNext()->getNext();
  }
  CartItem* temp = slow->getNext();
  slow->setNext(nullptr);
  return temp;
}

CartItem* Cart::mergeByName(CartItem* a, CartItem* b) {
  if (!a) return b;
  if (!b) return a;
  // Sort by product name
  if (a->getProductName() <= b->getProductName()) {
    a->setNext(mergeByName(a->getNext(), b));
    if(a->getNext()) a->getNext()->setPrev(a);
    a->setPrev(nullptr);
    return a;
  } else {
    b->setNext(mergeByName(a, b->getNext()));
    if(b->getNext()) b->getNext()->setPrev(b);
    b->setPrev(nullptr);
    return b;
  }
}


CartItem* Cart::sortNMergeByName(CartItem* head) {
  if (!head || !head->getNext()) {
    return head;
  }
  CartItem* second = getMidNode2Split(head);
  // Recursive split
  head = sortNMergeByName(head);
  second = sortNMergeByName(second);
  // Merge sorted linked list by name
  return mergeByName(head, second);
}

/** Final merge; Become a  public interface */
void Cart::nameMergeSortCart() {
  head = sortNMergeByName(head);
  // reset tail
  CartItem* temp = head;
  while (temp && temp->getNext()) {
    temp = temp->getNext();
  }
  tail = temp;
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

void Cart::getAllMatches(){
        std::string itemName;
        std::cout << "Enter a word to find: ";
        std::cin >> itemName;
        std::cout << "\nYour word was \'" << itemName << "\'.\n";
        CartItem* ptrCurr = (*this).getHead();
        int matches = 0;
        for(int i=0; i<(*this).size(); i++){
                if(ptrCurr -> getItem() . getProductName() == itemName){
                matches++;
                }
                ptrCurr = ptrCurr -> getNext();
        }
        std::cout << "We found " << matches << " matches.\n";

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

// Process finished with exit code -1073741819 (0xC0000005)
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