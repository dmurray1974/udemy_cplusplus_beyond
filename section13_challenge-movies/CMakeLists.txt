cmake_minimum_required(VERSION 4.0)
project(section13_challenge_movies)

set(CMAKE_CXX_STANDARD 20)

add_executable(section13_challenge_movies main.cpp
        Movie.h
        Movies.h
        Movie.cpp
        Movies.cpp)
