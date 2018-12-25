cmake_minimum_required(VERSION 3.10)
project(4_InfectionInTheOpenSpace)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wno-long-long -O2 -Wall -Wextra -pedantic")
add_executable(4_InfectionInTheOpenSpace main.cpp)