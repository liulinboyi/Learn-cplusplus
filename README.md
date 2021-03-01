# Learn C++

## Hello world!

```c++
// 流程： 预处理 => 编译器编译 => 链接器
// 引入头文件 iostream 实现了输入输出功能
#include
<stdio.h>

// main函数
int main() { // 入口函数，可以有参数，把外部文件传进来<返回值类型是int如果不写返回值，默认也返回0
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
        std::cout << "a == 2" << std::endl;
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
## 表达式

```c++
// 字面量表达式
// 常数字面量表达式
3;
5;

// 变量表达式
int x = 3;
x = x + 3;

//算术表达式
20 + 7;
20 - 7;
20 * 7;
20 / 7;
20 % 7;

// 关系表达式
20 < 7;
20 <= 7;
20 == 7;
20 > 7;
20 >= 7;

// 逻辑表达式
true and false;
true && false;
true or false;
true || false;
not true;
!true;

// 位运算表达式
5 & 3; // 每个二进制位进行运算（&操作）101 & 011
5 | 3; // 每个二进制位进行运算（|操作）101 | 011
~3; // 每个二进制位进行取反
5 ^ 3; // 每个二进制位进行异或操作，如果相对应的二进制位相同则该位为0，否则为1
5 << 1; // 二进制左移一位 相当于十进制数乘以2
5 >> 1; // 二进制右移一位 相当于十进制数除以2

// 条件表达式
true ? 1 : 0;

// 逗号表达式
1,2,3; // 通过逗号把任意数量表达式进行连接，保证从左到右依次计算，保证运算顺序，将最后一个表达式的结果，作为整个表达式的结果

// 函数调用表达式
 foo()
 
 // 赋值表达式
 x = 3;
 x += 3;
 x -= 3;
 x *= 3;
 x /= 3;
 x %= 3;
 
```

## 数组

```c++
// 数组定义
int array[5];
char words[6][6];

// 数组初始化
int array[5] = {1,2,3,4,5};
char words[6][6] = {
    {'o','n','e'},
    {'t','w','o'},
    {'t','h','r','e','e'}
};

// 数组访问
array[0] = 6;
int x = array[4];

words[3][0] = 'f';

// C语言风格字符串
char s1[] = "Hello";
char s2[] = {'H','e','l','l','o',0}; // 需要加一个0字符，0表示字符串结束

s1[1] = 'a';

std::cout << s1 << std::endl;


```
## 循环语句

```c++
// while
int n = 1;
while(n < 100) {
    std::cout << n << std::endl;
    n *= 2;
}

// do while
int n = 1;
do {
    std::cout << n << std::endl;
    n *= 2;
} while(n < 100)
    
// for
for(int n = 1;n < 100;n *= 2) {
    std::cout << n << std::endl;
}

// continue
for(int n = 1;n < 100;n++) {
    if(n == 50) {
        continue; // n等于50时，不执行下面的语句，快进到下一步，进入下一次循环
    }
    std::cout << n << std::endl;
}

// break
for(int n = 1;n < 100;n++) {
    if(n == 50) {
        break; // n等于50时，结束当前循环，退出
    }
    std::cout << n << std::endl;
}
```

## 声明语句

[变量声明代码](./array.cpp#L8)

```c++
// 变量声明
extern std::string name; // 声明，使用外部变量，告诉编译器，有个变量，不是我定义的，但是我想用，先定义后使用

// 函数声明
double cos(double x);

// 名字空间
// 不用每次都告诉编译器，这个对象是哪个名字空间下面的
using std::cout; // 省去单个，去名字空间下找对象，在后面直接使用cout就行
using namespace std; // 省去std名字空间下所有，去名字空间找对象，直接cout、cin就可以

// 类型别名
// 遇到模板时候，会再次使用带类型别名，
// 比如让一个模板处理很多种类型，首先给类型起一个别名，
// 不管类型真正的类型是什么，都叫做一个名字，通过这个类型的名字取处理他，
// 最终达到一份代码，来处理不同类型的目的
typedef int int_t;
using uint_t = unsigned int; // c++ 11 之后新的写法


```








