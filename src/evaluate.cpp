//
// Created by 81492 on 2021/3/2.
//

/*
 BNF
 <expr> ::= <expr> + <term>
         | <expr> - <term>
         | <term>

<term> ::= <term> * <factor>
         | <term> / <factor>
         | <factor>

<factor> ::= ( <expr> )
           | Num
 */

#include <iostream>
#include <memory>
#include <sstream>
#include <cassert>

struct Node {
    virtual double eval() const = 0;

    virtual std::string to_string() const = 0;
};

struct NumberNode : Node {
    NumberNode(double v) : value(v) {}

    double eval() const override {
        return value;
    }

    std::string to_string() const override {
        return std::to_string(value);
    }

private:
    double value;
};

enum BinaryOperator {
    PLUS = '+',
    SUBTRACT = '-',
    MULTIPLY = '*',
    DIVIDE = '/'
};

struct BinaryOperatorNode : Node {
    BinaryOperatorNode(std::shared_ptr<Node> lhs, BinaryOperator op, std::shared_ptr<Node> rhs) : lhs(lhs), op(op),
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

    std::string to_string() const override {
        return "(" + lhs->to_string() + std::string(1, op) + rhs->to_string() + ")";
    }

private:
    std::shared_ptr<Node> lhs;
    std::shared_ptr<Node> rhs;
    BinaryOperator op;
};

std::shared_ptr<Node> expression(std::istream &cin);

std::shared_ptr<Node> term(std::istream &cin);

std::shared_ptr<Node> factor(std::istream &cin);

/*
 BNF
 <expr> ::= <expr> + <term>
         | <expr> - <term>
         | <term>

<term> ::= <term> * <factor>
         | <term> / <factor>
         | <factor>

<factor> ::= ( <expr> )
           | Num
 */

std::shared_ptr<Node> expression(std::istream &cin) { // 并没有严格按照产生式去解析，而是在代码中消除了左递归
    std::shared_ptr<Node> left = term(cin);
    while (true) {
        char ch = cin.peek();
        switch (ch) {
            case '+':
                cin >> ch;
                left = std::make_shared<BinaryOperatorNode>(left, PLUS, term(cin));
                break;
            case '-':
                cin >> ch;
                left = std::make_shared<BinaryOperatorNode>(left, SUBTRACT, term(cin));
                break;
            default:
                return left;
        }
    }
}

std::shared_ptr<Node> term(std::istream &cin) {
    std::shared_ptr<Node> left = factor(cin);
    while (true) {
        char ch = cin.peek();
        switch (ch) {
            case '*':
                cin >> ch;
                left = std::make_shared<BinaryOperatorNode>(left, MULTIPLY, factor(cin));
                break;
            case '/':
                cin >> ch;
                left = std::make_shared<BinaryOperatorNode>(left, DIVIDE, factor(cin));
                break;
            default:
                return left;
        }
    }
}

std::shared_ptr<Node> factor(std::istream &cin) {
    char ch = cin.peek();
    if (ch == '(') {
        cin >> ch;
        std::shared_ptr<Node> ex = expression(cin);
        cin >> ch;
        assert(ch == ')');
        return ex;
    } else {
        double x;
        cin >> x;
        return std::make_shared<NumberNode>(x);
    }
}

double evaluate(const std::string &expr) {
    std::istringstream cin(expr);
    std::shared_ptr<Node> node = expression(cin);
    std::cout << node->to_string() << std::endl;
    return node->eval();
}

int main() {
    std::cout << evaluate("5*(4+(100-20))/2");
}