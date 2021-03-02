//
// Created by 81492 on 2021/3/2.
//
#include <iostream>
#include <memory>

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
struct BinaryOperatorNode : Node {
    BinaryOperatorNode(Node *lhs, BinaryOperator op, Node *rhs) : lhs(lhs), op(op),
                                                                  rhs(std::move(rhs)) {}

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
    Node *lhs;
    Node *rhs;
    BinaryOperator op;
};

int main() {
    using namespace std;
    NumberNode five(5);
    NumberNode four(4);
    NumberNode oneHundred(100);
    NumberNode twenty(20);
    NumberNode two(2);
    // 5*4
    BinaryOperatorNode mul(&five, MULTIPLY, &four);
    cout << five.eval() << endl;
    cout << five.eval() << (char) MULTIPLY << four.eval() << '=' << mul.eval() << endl;

    // 20/2
    BinaryOperatorNode div(&twenty, DIVIDE, &two);

    // 100 - 20/2
    BinaryOperatorNode sub(&oneHundred, SUBTRACT, &div);

    // 5*4 + 100 - 20/2
    BinaryOperatorNode plus(&mul, PLUS, &sub);

    cout << plus.eval() << endl;

//    // 5*4
//    NumberNode *res1 = new NumberNode((new BinaryOperatorNode(&five, MULTIPLY, &four))->eval());
//    // 5*4 + 100
//    NumberNode *res2 = new NumberNode((new BinaryOperatorNode(res1, PLUS, &oneHundred))->eval());
//    // 20/2
//    NumberNode *res3 = new NumberNode((new BinaryOperatorNode(&twenty, DIVIDE, &two))->eval());
//    //5*4 + 100 - 20/2
//    NumberNode res5 = (new BinaryOperatorNode(res2, SUBTRACT, res3))->eval();
//    // 5*4 + 100 - 20/2
//    cout << res5.eval() << endl;
}














