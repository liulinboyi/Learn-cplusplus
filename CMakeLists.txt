cmake_minimum_required(VERSION 3.17)
project(cplus)

set(CMAKE_CXX_STANDARD 14)

add_executable(cplus
        example/hello.cpp)
add_executable(cplus1
        example/switch.cpp example/calculate.cpp)
add_executable(cplus2
        example/array.cpp example/Statement.cpp)
add_executable(cplus3
        example/Combination-type.cpp)
add_executable(cplus5
        example/pointer.cpp)
add_executable(cplus6
        example/class.cpp)
