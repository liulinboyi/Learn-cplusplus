cmake_minimum_required(VERSION 3.17)
project(cplus)

set(CMAKE_CXX_STANDARD 14)

add_executable(cplus
        hello.cpp)
add_executable(cplus1
        switch.cpp src/calculate.cpp)
add_executable(cplus2
        array.cpp Statement.cpp)