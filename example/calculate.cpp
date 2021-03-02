//
// Created by 81492 on 2021/3/2.
//
#include <iostream>


double calculate1() {
    using namespace std;

    char op = ' ';
    double lhs, rhs, res;

    while (true) {
        cin >> lhs >> op >> rhs;
        switch (op) {
            case '+':
                res = lhs + rhs;
                break;
            case '-':
                res = lhs - rhs;
                break;
            case '*':
                res = lhs * rhs;
                break;
            case '/':
                res = lhs / rhs;
                break;
            default:
                std::cout << "Operator wrong" << std::endl;
                continue;
        }
        cout << res << endl;
    }
}


double calculate() {
    using namespace std;

    double z;
    // std（标准库）cout 输出
    cout << "hello! ";
    cout << "the program is start!" << endl; // 换行

    while (true) {
        double x = 0;
        double y = 0;
        char c = ' ';

        const char *tips = "请输入(please input):";
        cout << tips << ends;
        cin >> x >> c >> y; // 输入 x,c(操作符),y
        cout << "输入长度:" << cin.gcount() << endl;

//        cout << typeid(x).name() << endl;
//        cout << typeid(c).name() << endl;
//        cout << typeid(y).name() << endl;

        cout << "输入解析为：" << "x=" << x << "c=" << c << "y=" << y << endl;

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
            default:
                cout << "输入错误，退出" << endl;
                exit(1);
        }
        cout << "结果是：" << x << c << y << '=' << z << endl;
    }
    return z;
}



