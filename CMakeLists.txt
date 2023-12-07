cmake_minimum_required(VERSION 3.26)
project(HashingProj)

set(CMAKE_CXX_STANDARD 23)

add_executable(Hashing main.cpp
        Inventory.cpp
        Inventory.h
        store.cpp
        store.h
        Product.cpp
        Product.h
        CartItem.cpp
        CartItem.h
        Cart.cpp
        Cart.h
)

