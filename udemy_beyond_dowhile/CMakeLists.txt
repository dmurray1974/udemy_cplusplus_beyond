cmake_minimum_required(VERSION 4.0)
project(udemy_beyond_dowhile)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(spdlog REQUIRED)

add_executable(udemy_beyond_dowhile main.cpp)
target_link_libraries(udemy_beyond_dowhile PRIVATE spdlog::spdlog)
