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
add_executable(cplus7
        example/share_ptr.cpp)
add_executable(cplus8
        src/evaluate.cpp)
add_executable(cplus9
        src/evaluate1.cpp)
add_executable(cplus10
        example/template.cpp)
add_executable(cplus11
        example/string.cpp)
add_executable(cplus12
        example/vector.cpp)
add_executable(calculate
        src/main.cpp)
