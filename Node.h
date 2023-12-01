// todo: Mod更多

#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node{
private:
  std::string data;
  Node* next;
  Node* previous;

public:
  void setData(std::string);
  void setWord(std::string);
  void setNext(Node*);
  void setPrevious(Node*);
  void setPrev(Node*);
  std::string getData();
  std::string getWord();
  Node* getNext();
  Node* getPrevious();
  Node* getPrev();
  bool operator==(Node);
  bool operator!=(Node);
  bool operator<(Node);
  bool operator>(Node);
  bool operator<=(Node);
  bool operator>=(Node);
  Node();
  ~Node();
  Node(std::string);
  Node(std::string, Node*);
  Node(std::string, Node*, Node*);
  bool operator==(std::string);
  bool operator!=(std::string);
  bool operator>(std::string);
  bool operator<(std::string);
  bool operator>=(std::string);
  bool operator<=(std::string);
};

bool operator==(std::string data, Node node);
bool operator!=(std::string data, Node node);
bool operator>=(std::string data, Node node);
bool operator<=(std::string data, Node node);
bool operator>(std::string data, Node node);
bool operator<(std::string data, Node node);

#endif