//
// Created by 81492 on 2021/3/2.
//
#include <iostream>
#include <memory>

using namespace std;

struct Node {
    // 统一的方法，本身不用实现
    // 虚函数是指一个类中你希望重载的成员函数
    virtual double eval() const = 0;

};

// 表达式节点，数字节点
struct NumberNode : Node {
    NumberNode(double v) : value(v) {}

// 数值节点运算，返回数值本身
    double eval() const override {
        return value;
    }

private:
    double value;;

};

enum BinaryOperator {
    PLUS = '+',
    SUBTRACT = '-',
    MULTIPLY = '*',
    DIVIDE = '/'
};

// 表达式节点，二叉操作节点
// 将裸指针改为shared_ptr
struct BinaryOperatorNode : Node {
    BinaryOperatorNode(shared_ptr<Node> lhs, BinaryOperator op, shared_ptr<Node> rhs) : lhs(lhs), op(op),
                                                                                        rhs(rhs) {}

    double eval() const override {
        switch (op) {
            case PLUS:
                return lhs->eval() + rhs->eval();
            case SUBTRACT:
                return lhs->eval() - rhs->eval();
            case MULTIPLY:
                return lhs->eval() * rhs->eval();
            case DIVIDE:
                return lhs->eval() / rhs->eval();
            default:
                exit(1);
        }
    }


private:
    shared_ptr<Node> lhs;
    shared_ptr<Node> rhs;
    BinaryOperator op;
};

int main() {
    using namespace std;
//    NumberNode five(5);
//    NumberNode four(4);
//    NumberNode oneHundred(100);
//    NumberNode twenty(20);
//    NumberNode two(2);
//    // 5*4
//    BinaryOperatorNode mul(make_shared<NumberNode>(five), MULTIPLY, make_shared<NumberNode>(four));
//    cout << five.eval() << endl;
//    cout << five.eval() << (char) MULTIPLY << four.eval() << '=' << mul.eval() << endl;
//
//    // 20/2
//    BinaryOperatorNode div(make_shared<NumberNode>(twenty), DIVIDE, make_shared<NumberNode>(two));
//
//    // 100 - 20/2
//    BinaryOperatorNode sub(make_shared<NumberNode>(oneHundred), SUBTRACT, make_shared<BinaryOperatorNode>(div));
//
//    // 5*4 + 100 - 20/2
//    BinaryOperatorNode plus(make_shared<BinaryOperatorNode>(mul), PLUS, make_shared<BinaryOperatorNode>(sub));
//
//    cout << plus.eval() << endl;


// 5*4+100-20/2
    double x;
    cin >> x;
    shared_ptr<Node> node(new NumberNode(x));

    char ch; // 符号
    while (cin >> ch >> x) {
        cout << "ch:" << ch << endl;
        cout << "x:" << x << endl;
        cout << cin.peek() << endl;
//        cout << "回车" << (int) '\n' << endl;
//        char c = cin.get();
//        cout << c << endl;
        switch (ch) {
            case '+':
                node = make_shared<BinaryOperatorNode>(node, PLUS, make_shared<NumberNode>(x));
                break;
            case '-':
                node = make_shared<BinaryOperatorNode>(node, SUBTRACT, make_shared<NumberNode>(x));
                break;
            case '*':
                node = make_shared<BinaryOperatorNode>(node, MULTIPLY, make_shared<NumberNode>(x));
                break;
            case '/':
                node = make_shared<BinaryOperatorNode>(node, DIVIDE, make_shared<NumberNode>(x));
                break;
            default:
                exit(1);
        }
        if ((char) cin.peek() == '\n') {
            break;
        }
    }
    cout << "node.eval()" << node->eval() << endl;
}














