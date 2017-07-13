cmake_minimum_required(VERSION 3.7)
project(patest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ds/Basic/union.cpp ds/List/LinearList.c)
add_executable(patest ${SOURCE_FILES})