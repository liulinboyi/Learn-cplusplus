//
// Created by 81492 on 2021/3/2.
//
#include <iostream>

int main() {
    using namespace std;
    int a = 1;
    // 指针同样是变量，只不过这个变量里面存的是内存地址，
    // 其中int表示指针指向什么类型的变量，
    // *表示标识这是个指针变量（取地址的值，解引用），
    // &表示取（内存）地址运算符，
    // 最后整体表示，取a的内存地址，赋值给了p
    int *p = &a;
    auto s = &a; // s存放a的（内存）地址
    // 从这里看 int *p = &a;非常像是上面两句的语法糖，不知道理解的对不对
    cout << "s: " << s << endl;
    cout << "*s: " << *s << endl;

    cout << "------------------------" << endl;

    // or
    // int* q; 比较好理解，就是声明一个int类型指针，q，可以存储（int类型变量的）内存地址
    int *q; // 表示声明q是一个可以保存int类型变量内存地址的变量
    q = &a;

    void *v;
    v = &a;

    cout << "q: " << q << endl;
    cout << "*q: " << *q << endl;

    cout << "v: " << v << endl;

    cout << "------------------------" << endl;

    cout << "*p: " << *p << endl; // p里面存放的是a的地址，*p是把a的地址的值取出来
    cout << "a: " << a << endl;
    cout << "p: " << p << endl; // a的内存地址，赋值给了p
    cout << "&a: " << &a << endl;
    cout << "&p: " << &p << endl;
    cout << "*&p: " << *&p << endl;


    cout << "------------------------" << endl;
    a = 10;

    // 基本数据类型也可以是引用的也可以不是，和其他语言有很大不同呀，比如Java、javas基本数据类型都不能是引用的，自己的理解
    // 值得注意的是，a的值改变了，自然而然，*p的值也跟着改变，p本来存储的就是a的内存地址，*p是去a的内存地址去取值（解引用），当然跟着变了


    cout << "*p: " << *p << endl; // p里面存放的是a的地址，*p是把a的地址的值取出来
    cout << "a: " << a << endl;
    cout << "p: " << p << endl; // a的内存地址，赋值给了p
    cout << "&a: " << &a << endl;
    cout << "&p: " << &p << endl;
    cout << "*&p: " << *&p << endl;

    cout << "------------------------" << endl;

    cout << "s: " << s << endl;
    cout << "*s: " << *s << endl;

}