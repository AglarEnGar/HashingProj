// todo: Mod更多

#include "hList.h"
using namespace std;

hList::hList(){
  this->head = nullptr;
  this->tail = nullptr;
  this->linkedSize = 0;
}

hList::hList(string data){
  Node* newNode = new Node(data);
  this->head = newNode;
  this->tail = newNode;
  this->linkedSize++;
}

hList::~hList(){
  while(this->linkedSize != 0){
    this->linkedSize--;
    Node* deleteNode = this->getHead();
    this->head = this->head->getNext();
    delete deleteNode;
  }
  this->head = nullptr;
  this->tail = nullptr;
}

Node*hList::getHead(){
  return this->head;
}

Node*hList::getTail(){
  return this->tail;
}

void hList::setHead(Node* head){
  this->head = head;
}

void hList::setTail(Node* tail){
  this->tail = tail;
}

void hList::createLinkedList(int dictNumber){
  ifstream dFile;
  string inputString;
  string stringNumber = to_string(dictNumber);
  string fileName = "dictionary" + stringNumber + ".txt";
  dFile.open(fileName);
  while(dFile >> inputString){
    this->push_back(inputString);
  }
  dFile.close();
}

void hList::push_back(string newWord){
  this->linkedSize++;
  if(this->head == nullptr){
    Node* newNode = new Node(newWord);
    //newNode->setData(newWord);
    this->head = newNode;
    this->tail = newNode;
  } else{
    Node* newNode = new Node(newWord, this->tail);
    this->tail->setNext(newNode);
    this->tail = newNode;
  }
}

Node*hList::insert_before(string newWord, Node * nextNode){
  this->linkedSize++;
  Node* newNode = new Node(newWord);
  newNode->setNext(nextNode);
  if(this->head == nextNode){
    this->head = newNode;
  } else {
    newNode->setPrev(nextNode->getPrev());
    nextNode->getPrev()->setNext(newNode);
  }
  nextNode->setPrev(newNode);
  return newNode;
}

Node*hList::checkOrder(string data){
  Node* afterNode = nullptr;
  if(this->head != nullptr){
    Node* checkNode = this->head;
    while(checkNode != nullptr){
      if(data < checkNode->getData()){
        afterNode = checkNode;
        return afterNode;
      }
      checkNode = checkNode->getNext();
    }
  }
  return afterNode;
}

void hList::deleteWord(Node* inputNode){
  if(inputNode->getPrev() != nullptr){
    inputNode->getPrev()->setNext(inputNode->getNext());
  } else {
    this->head = nullptr;
  }
  if(inputNode->getNext() != nullptr){
    inputNode->getNext()->setPrev(inputNode->getPrev());
  } else {
    this->tail = nullptr;
  }
  delete inputNode;
  this->linkedSize--;
}

void hList::writeToFile(string fileName){
  if(this->head != nullptr){
    ofstream outputFile;
    outputFile.open(fileName);
    Node* printNode = this->head;
    while(printNode != nullptr){
      outputFile << printNode->getData() << "\n";
      printNode = printNode->getNext();
    }
    outputFile.close();
  }
}

void hList::printWords(){
  if(this->linkedSize != 0){
    Node* printNode = this->head;
    while(printNode != nullptr){
      cout << "\n" << printNode->getData();
      printNode = printNode->getNext();
    }
  }
}

int hList::size(){
  return this->linkedSize;
}

/*int hList::size(){
   if(this->head == nullptr){
      return 0;
   }
   int size = 0;
   Node* checkNode = this->head;
   while(checkNode != nullptr){
      size++;
      checkNode = checkNode->getNext();
   }
   return size;
}*/