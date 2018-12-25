cmake_minimum_required(VERSION 3.10)
project(2_TrackConstruction)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wno-long-long -O2 -Wall -Wextra -pedantic")

add_executable(2_TrackConstruction main.cpp)