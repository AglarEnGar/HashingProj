cmake_minimum_required(VERSION 3.26)
project(HashingProj)

set(CMAKE_CXX_STANDARD 23)

add_executable(run main.cpp Product.cpp CartItem.cpp Inventory.cpp Cart.cpp User.cpp Store.cpp Test.cpp)