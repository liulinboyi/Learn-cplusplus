//
// Created by 81492 on 2021/3/1.
//
#include <iostream>
#include <sstream>
#include <string>

int main() {
    char array[] = "Hello";
    array[1] = 'a';

    int size = sizeof(array)/*查看占用内存大小 array5个字符但是大小是6，最后又一个0，表示字符串结束*/;

    std::string c = "sizeof array: ";

    std::stringstream ss;

    ss << c << size;

    std::string res = ss.str();

    std::cout << res << std::endl;

    std::cout << array << std::endl;
}