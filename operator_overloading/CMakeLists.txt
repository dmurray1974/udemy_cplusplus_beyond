cmake_minimum_required(VERSION 4.0)
project(operator_overloading)

set(CMAKE_CXX_STANDARD 20)

add_executable(operator_overloading main.cpp
        Mystring.h
        Mystring.cpp
        Money.h
        Money.cpp)
