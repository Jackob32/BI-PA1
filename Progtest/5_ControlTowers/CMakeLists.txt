cmake_minimum_required(VERSION 3.10)
project(5_ControlTowers C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wno-long-long -O2 -Wall -Wextra -pedantic")

add_executable(5_ControlTowers
        main.c)
