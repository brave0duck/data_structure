cmake_minimum_required(VERSION 3.10.0)
project(BinaryTree VERSION 0.1.0 LANGUAGES C)

add_executable(BinaryTree BinaryTree.c main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
