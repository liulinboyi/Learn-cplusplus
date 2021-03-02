cmake_minimum_required(VERSION 3.17)
project(cplus)

set(CMAKE_CXX_STANDARD 14)

add_executable(cplus
        src/hello.cpp)
add_executable(cplus1
        src/switch.cpp src/calculate.cpp)
add_executable(cplus2
        src/array.cpp src/Statement.cpp)
add_executable(cplus3
        src/Combination-type.cpp)