//
// Created by 81492 on 2021/3/7.
//
#include <iostream>
#include <deque>

int main() {
    // 双端队列
    // push_front()
    // pop_front()
    // push_back()
    // pop_back()
    using namespace std;
    deque<int> d = {1, 2, 3, 4, 5};
    // stack 操作
    cout << "stack 操作: " << endl;
    d.push_back(6); // 入栈
    d.pop_back(); // 出栈
    for (int item : d) {
        cout << item << endl;
    }
    cout << "-----------------" << endl;
    // queue操作
    cout << "queue操作: " << endl;
    d.push_back(6); // 队尾入队
    d.pop_front(); // 队首出队
    for (int item : d) {
        cout << item << endl;
    }

}



























