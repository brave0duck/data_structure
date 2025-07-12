cmake_minimum_required(VERSION 3.10.0)
project(disjoinset VERSION 0.1.0 LANGUAGES C)

add_executable(disjoinset main.c disjoinset.c)

include(CTest)
enable_testing()

