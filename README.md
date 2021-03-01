# Learn C++

## Hello world!

```c++
// 流程： 预处理 => 编译器编译 => 链接器
// 引入头文件 iostream 实现了输入输出功能
#include
<stdio.h>

// main函数
int main()
{ // 入口函数，可以有参数，把外部文件传进来<返回值类型是int如果不写返回值，默认也返回0
printf("hello world!\n");

return 0;
}

```

## void类型指针可以表示任何类型，void类型是一个非常有用的类型

## 整形指针只能表示整形；浮点数的指针只能表示浮点型；

## 变量定义、变量赋值、变量取值

```c++
// 定义
int year = 2021;
unsigned long date = 20210225;
long double pi = 3.14159;
char dot = '.';
// 赋值
int x = 1;
x = 2;
x = 3 + 4;
x = x + 5;
// 取值
int x = 1;
std::cout << x << std::endl;
int y = x + 1;
// const修饰符
const int a = 3;
```

## 选择语句

```c++
// 关系运算法:
// < | <= | > | >= | == | !=

// if条件语句
int a = 3;
if (a > 2) {
    std::cout << "a > 2" << std::endl;
}

if (a != 5) {
    std::cout<< "a != 5" << std::endl;
}

// else

if (a < 2) {
    std::cout << "a < 2" << std::endl;
} else {
    std::cout << "a >= 2" << std::endl;
}

// else if

if (a < 2) {
    std::cout << "a < 2" << std::endl;
} else if (a > 2) {
    std::cout << "a > 2" << std::endl;
} else {
    std::cout << "a == 2" << std::endl;
}

// 相当于:
// 从 a < 2 分成了两个大分支，后面是一个小分支
if (a < 2) {
    std::cout << "a < 2" << std::endl;
} else {
    if (a > 2) {
        std::cout << "a > 2" << std::endl;
    } else {
    s   td::cout << "a == 2" << std::endl;
    }
}


// switch
int a = 3;

switch(a) {
    case 1:
        std::cout << "a is 1" << std::endl;
        break;
    case 2:
        std::cout << "a is 1" << std::endl;
        break;
    default:
        std::cout << "a is not 1 ant 2" << std::endl;
        break;
}

```













