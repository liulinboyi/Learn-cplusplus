//
// Created by 81492 on 2021/3/1.
//

// 流程： 预处理 => 编译器编译 => 链接器
// 引入头文件 iostream 实现了输入输出功能
#include <stdio.h>
#include <cmath>
#include <iostream>

// main函数
int main() { // 入口函数，可以有参数，把外部文件传进来<返回值类型是int如果不写返回值，默认也返回0
    using namespace std;
    double cos(double x); // 函数声明
    int add(int x, int y); // 函数声明
    printf("hello world!\n");

    cout << "cos: " << round(cos(M_PI / 2.0)) << endl;
    cout << "add: " << add(1, 2) << endl;

    return 0;
}

int add(int a, int b) {
    return a + b;
}
