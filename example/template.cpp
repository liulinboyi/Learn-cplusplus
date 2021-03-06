//
// Created by 81492 on 2021/3/5.
//
#include <iostream>
#include <ostream>
#include <cmath>

using namespace std;

// 模板
template<typename T>
// template<typename T=int> // 类型可以有默认值，有了默认值，模板实例化时可以不传类型
// 结构体
// struct 和 class本质上一样，只不过struct默认为public
struct Point {
    T x;
    T y;
};

struct pointer {
    // 成员函数模板
    template<typename T>
    void print(T x);
};

template<typename T>
void pointer::print(T x) {
    using namespace std;
    cout << x << endl;
}

// 模板特化
template<typename T>
T Q_rsqrt(T x) {
    return T(1) / sqrt(x);
//    return T(1) / sqrt(x);
}

// 模板特化 特例实现
// template 然后一个空列表
template<>
// 函数签名 把类型参数替换成具体的类型，然后进行实现
float Q_rsqrt(float x) { // 平方根倒数速算法
    long i;
    float x2, y;

    x2 = x * 0.5F;
    y = x;
    i = *(long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *) &i;
    y = y * (1.5f - (x2 * y * y));
    return y;
}

template<typename T>
void f(T x) {
    using namespace std;
    cout << "void f(T x)" << endl;
}

// 特化
template<>
void f(double x) {
    using namespace std;
    cout << "void f(double x)" << endl;
}

int main() {
    // 模板实例化
    Point<int> p0 = {10, 20};
    Point<double> p1 = {10.5, 20.6};
    cout << p0.x << ", " << p1.x << endl;
    cout << p0.y << ", " << p1.y << endl;

    cout << "sizeof(Point<int>)" << endl;
    cout << sizeof(Point<double>) << endl;
    // Point<int> 和 Point<double>编译代码后是两个不同的类

    cout << "-----------------" << endl;

    // 成员函数模板
    pointer p;
    p.print(10);

    cout << "-----------------" << endl;

    cout << Q_rsqrt(2.0f) << endl; // float
    cout << Q_rsqrt(2.0) << endl; // double
    cout << Q_rsqrt(2) << endl; // int

    cout << "-----------------" << endl;

    f(10); // int
    f(20.0); // double

}
