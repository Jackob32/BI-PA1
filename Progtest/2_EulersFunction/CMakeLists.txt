cmake_minimum_required(VERSION 3.10)
project(2_EulersFunction)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -W -Wno-long-long -O2 -Wall -Wextra -pedantic")

add_executable(2_EulersFunction
        .idea/2_EulersFunction.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/workspace.xml
        main.cpp
        README.md)
