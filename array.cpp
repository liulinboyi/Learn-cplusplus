//
// Created by 81492 on 2021/3/1.
//
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdint>
#include <climits>

extern std::string name; // 声明，使用外部变量，告诉编译器，有个变量，不是我定义的，但是我想用，先定义后使用

int main() {
    using namespace std;
    char array[] = "Hello";
    array[1] = 'a';
    int32_t i; // 类型别名

    int size = sizeof(array)/*查看占用内存大小 array5个字符但是大小是6，最后又一个0，表示字符串结束*/;

    cout << name << ends;
    string c = "sizeof array: ";

    stringstream ss;

    ss << c << size;

    string res = ss.str();

    cout << res << endl;

    cout << array << endl;
}