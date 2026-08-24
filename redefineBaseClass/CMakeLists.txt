cmake_minimum_required(VERSION 4.0)
project(redefineBaseClass)

set(CMAKE_CXX_STANDARD 20)

add_executable(redefineBaseClass main.cpp
        Account.h
        Account.cpp
        Savings_Account.cpp
        Savings_Account.h
        Account_Util.h
        Account_Util.cpp
        Checking_Account.h
        Checking_Account.cpp
        Trust_Account.h
        Trust_Account.cpp)
