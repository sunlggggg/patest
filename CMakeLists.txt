cmake_minimum_required(VERSION 3.7)
project(patest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ds/List/SearchExchangeInsert_Star018-9.cpp)
add_executable(patest ${SOURCE_FILES})