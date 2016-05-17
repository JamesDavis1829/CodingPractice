cmake_minimum_required(VERSION 3.3)
project(AVL_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES avlTree.c avlTree.h queue.c queue.h)
add_executable(AVL_Tree ${SOURCE_FILES})