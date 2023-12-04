# Shopping System Project Proposal

## Overview

This project aims to develop an object-oriented shopping system to meet users' shopping needs. The system will 
include core functionalities such as product management, shopping cart, inventory, user management, and store 
management. We will implement this system using C++ and utilize standard LinkedList and hashmap as well as a custom 
doubly-linked list data structure.

## UML Diagram

![readMeUML.png](readMeUML.png)

## Inheritance and Composition

In the project, we employ the concepts of inheritance and composition to build relationships between classes.

- **Inheritance:** We utilize inheritance to create the `CartItem` class, which inherits from the `Product` class. This signifies that a `CartItem` is a specialized type of `Product` and inherits the attributes and methods of `Product`.

- **Composition:** We use composition to establish the relationships between the shopping cart (`Cart`) and inventory (`Inventory`) with products (`Product`). The shopping cart contains multiple cart items (`CartItem`), forming a composition relationship. The inventory contains multiple products, also forming a composition relationship.

## Communication

Different objects communicate through functions to implement system functionalities. For instance, users can add products to the shopping cart, which involves the shopping cart object calling its method to add items. The shopping cart can also calculate the total price of items in the cart, requiring communication with cart item (`CartItem`) objects.

## Development Stages Plan

The project development will be divided into the following stages:

### Current Stage

- Complete the basic framework of the shopping system, including product management, shopping cart, inventory, user management, and store management functionalities.
- Implement basic inheritance and composition relationships.
- Write simple test cases to validate basic functionalities.

### Future Stages

- Add advanced features such as user authentication, order management, and payment processing.
- Perform performance optimization to ensure the system can handle large-scale data.
- Enhance documentation and comments for code understanding and maintenance by team members.
- Conduct system integration testing to ensure smooth functionality.
