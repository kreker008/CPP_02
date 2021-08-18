cmake_minimum_required(VERSION 3.16.3)
project(ex_00)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex_00
        Fixed.cpp
        Fixed.hpp
        main.cpp)
