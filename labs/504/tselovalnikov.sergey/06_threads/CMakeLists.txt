cmake_minimum_required(VERSION 2.8.4)
project(06_threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -pthread")

set(SOURCE_FILES main.cpp)
add_executable(06_threads ${SOURCE_FILES})

