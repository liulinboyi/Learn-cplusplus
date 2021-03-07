//
// Created by 81492 on 2021/3/7.
//
#include <iostream>
#include <vector>

int main() {
    // 向量 可以存任意类型
    // vector()
    // vector(n,el)
    // vector({el1,el2,el3,...})
    // vector(vec)
    // vector(std::move(vec))
    using namespace std;
    //    模板参数
    vector<int> v = {1, 2, 3, 4};
    for (int item : v) {
        cout << item << endl;
    }
    cout << "vector.at()" << endl;
    cout << v.at(2) << endl;
    vector<int> v2 = v;
    vector<int> v3 = move(v); // 此时v为空，将v移动拷贝的
    cout << "size(): " << "v: " << v.size() << "; v2: " << v2.size() << "; v3: " << v3.size() << endl;

    cout << "-----------------------" << endl;

    // 方法
    // push_back()
    // pop_back()
    // data() // 获取C语言底层数据的指针，来调用C语言的函数
    // size()
    // reserve() // 预先留存多大空间，预估此次需要多大空间，减少运行时扩容损耗
    // at() // 下标访问

}




































