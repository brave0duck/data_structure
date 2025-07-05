# CMake 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.10)

# 프로젝트 정보
project(Deque VERSION 0.1  DESCRIPTION "Deque"  LANGUAGES C)

add_executable (Deque main.c Deque.c Deque.h)
