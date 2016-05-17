cmake_minimum_required(VERSION 3.3)
project(LinearHashedTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c HashTable.c HashTable.h)
add_executable(LinearHashedTable ${SOURCE_FILES})