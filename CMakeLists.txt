cmake_minimum_required(VERSION 3.26)
project(HashingProj)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp Product.cpp CartItem.cpp Inventory.cpp Cart.cpp User.cpp Store.cpp)