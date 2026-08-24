cmake_minimum_required(VERSION 4.0)
project(inheritance)

set(CMAKE_CXX_STANDARD 20)

add_executable(inheritance main.cpp
        Account.h
        Account.cpp
        SavingsAccount.h
        SavingsAccount.cpp
        Savings_Account.h
        Savings_Account.cpp)
