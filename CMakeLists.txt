cmake_minimum_required(VERSION 3.30)

project(MemoryAllocater)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wextra -Werror -Wpedantic")

add_executable(MemoryAllocater main.cpp)