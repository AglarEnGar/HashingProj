cmake_minimum_required(VERSION 3.26)
project(Hashing)

set(CMAKE_CXX_STANDARD 23)

add_executable(Hashing main.cpp
        Inventory.cpp
        store.cpp
        Product.cpp
        CartItem.cpp
        Cart.cpp
)
