// todo: Mod更多

#include "Node.h"
using namespace std;

void Node::setData(string data){
  this->data = data;
}

void Node::setWord(string data){
  this->data = data;
}

void Node::setNext(Node* next){
  this->next = next;
}

void Node::setPrevious(Node* previous){
  this->previous = previous;
}

void Node::setPrev(Node* previous){
  this->previous = previous;
}

string Node::getData(){
  return this->data;
}

string Node::getWord(){
  return this->data;
}

Node* Node::getPrev(){
  return this->previous;
}

Node* Node::getNext(){
  return this->next;
}

Node* Node::getPrevious(){
  return this->previous;
}

bool Node::operator==(Node other){
  if(this->getData() == other.getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator!=(Node other){
  if(this->getData() != other.getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator>(Node other){
  if(this->getData() > other.getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator<(Node other){
  if(this->getData() < other.getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator<=(Node other){
  if(this->getData() <= other.getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator>=(Node other){
  if(this->getData() >= other.getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator==(string data){
  if(data == this->getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator!=(string data){
  if(data != this->getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator>(string data){
  if(data < this->getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator<(string data){
  if(data > this->getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator>=(string data){
  if(data <= this->getData()){
    return true;
  } else{
    return false;
  }
}

bool Node::operator<=(string data){
  if(data >= this->getData()){
    return true;
  } else{
    return false;
  }
}

Node::Node(){
  this->previous = nullptr;
  this->next = nullptr;
}

Node::Node(string data){
  this->data = data;
  this->previous = nullptr;
  this->next = nullptr;
}

Node::Node(string data, Node* previous){
  this->data = data;
  this->previous = previous;
}

Node::~Node(){
  this->next = nullptr;
  this->previous = nullptr;
}

Node::Node(string data, Node* previous, Node* next){
  this->data = data;
  this->previous = previous;
  this->next = next;
}

bool operator==(std::string data, Node node) {
  if(data == node.getData()){
    return true;
  } else{
    return false;
  }
}

bool operator!=(std::string data, Node node) {
  if(data != node.getData()){
    return true;
  } else{
    return false;
  }
}

bool operator>=(std::string data, Node node) {
  if(data >= node.getData()){
    return true;
  } else{
    return false;
  }
}

bool operator<=(std::string data, Node node) {
  if(data <= node.getData()){
    return true;
  } else{
    return false;
  }
}

bool operator>(std::string data, Node node) {
  if(data > node.getData()){
    return true;
  } else{
    return false;
  }
}

bool operator<(std::string data, Node node) {
  if(data < node.getData()){
    return true;
  } else{
    return false;
  }
}