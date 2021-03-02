//
// Created by 81492 on 2021/3/2.
//
#include <iostream>
#include <memory>

int main() {
    // std::share_ptr 避免内存泄露，内存管理

    using namespace std;
    shared_ptr<int> p(new int(3)); // 第一种初始化
    p = make_shared<int>(5); // 第二种初始化
    cout << "*p:" << *p << endl;

    {
        shared_ptr<int> q(p);
        cout << "*q:" << *q << endl;
        cout << "p.use_count():" << p.use_count() << endl; // 引用计数 2
    }

    cout << "p.use_count():" << p.use_count() << endl; // 引用计数 1，这里，出了上面的作用域，q已经自动销毁了

}