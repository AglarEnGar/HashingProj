// todo: Mod更多

#ifndef HLIST_H
#define HLIST_H

#include "Node.h"
#include <fstream>

struct hList {
private:
  Node* tail;
  Node* head;
  int linkedSize;

public:
  hList();
  hList(std::string);
  ~hList();
  Node* getHead();
  Node* getTail();
  void setHead(Node*);
  void setTail(Node*);
  void createLinkedList(int);
  void push_back(std::string);
  Node* insert_before(std::string, Node*);
  Node* checkOrder(std::string);
  void deleteWord(Node*);
  void writeToFile(std::string);
  void printWords();
  int size();

};

#endif