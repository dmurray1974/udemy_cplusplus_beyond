cmake_minimum_required(VERSION 4.0)
project(sec13_account)

set(CMAKE_CXX_STANDARD 20)

add_executable(sec13_account main.cpp
        Account.h
        Account.cpp)
