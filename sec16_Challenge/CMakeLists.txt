cmake_minimum_required(VERSION 4.0)
project(sec16_Challenge)

set(CMAKE_CXX_STANDARD 20)

add_executable(sec16_Challenge
        main.cpp
        Account.cpp
        Account.h
        Account.cpp
        Savings_Account.cpp
        Savings_Account.h
        Account_Util.h
        Account_Util.cpp
        Checking_Account.h
        Checking_Account.cpp
        Trust_Account.h
        Trust_Account.cpp
        I_Printable.h
        I_Printable.cpp
)
