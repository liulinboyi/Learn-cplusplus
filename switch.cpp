//
// Created by 81492 on 2021/3/1.
//

#include <iostream>

int main() {
    using namespace std;

    const char *tips = "请输入:";

    cout << tips << ends;

    int x;
    int y;
    char c;
    int z;
    cin >> x >> c >> y; // 输入 x,c(操作符),y

    switch (c) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
    }
    cout << z << endl;
    return z;
}