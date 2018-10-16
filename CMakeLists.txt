cmake_minimum_required(VERSION 2.8.4)
project(HeapAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall -pedantic")

add_executable(maxheap.out maxheap.cpp)
add_executable(minheap.out minheap.cpp)

