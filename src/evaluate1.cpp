//
// Created by 81492 on 2021/3/3.
//

// EBNF
// https://bottlecaps.de/rr/ui
/*
expr      ::= term expr_tail
expr_tail ::= (("+" | "-") term expr_tail)?
term      ::= factor term_tail
term_tail ::= (("*" | "/") factor term_tail)?
factor    ::= "(" expr ")" | Num
Num       ::= [0-9]+

*/
#include <cstdio>
#include <cstdlib>
#include <iostream>

// 词法分析器 开始
enum {
    Num
};
using namespace std;
int token;
int token_val;
char *line = nullptr;
char *src = nullptr;

void next() {
    // skip white space
    while (*src == ' ' || *src == '\t') {
        src++;
    }

    printf("before: %s", src);
    cout << "" << endl; // c++，cout有输出缓存区，攒到一定字符才输出一次，或者遇到endl就不赞了直接输出

    token = *(src++); // 字符串数组，src++，表示字符串数组，头指针向后移，将值赋给token
    printf("after: %s", src);
    cout << "token: " << (char) token << endl;
    cout << "吃掉了: " << (char) token << endl;

    if (token >= '0' && token <= '9') {
        token_val = token - '0';
        token = Num; // 重置token

        while (*src >= '0' && *src <= '9') {
            token_val = token_val * 10 + *src - '0';
            src++;
        }
        return;
    }
}

void match(int tk) {
    if (token != tk) {
        printf("expected token: %d(%c), got: %d(%c)\n", tk, tk, token, token);
        exit(-1);
    }
    next();
}

// 词法分析器 结束

// 语法分析器 开始
int expr();

int factor() { // ( <expr> ) | Num  ，可能是带括号的表达式，或者数字
    int value = 0;
    if (token == '(') {
        match('(');
        value = expr();
        match(')');
    } else {
        value = token_val;
        match(Num);
    }
    return value;
}

int term_tail(int lvalue) { // * <factor> <term_tail> | / <factor> <term_tail> | <empty>
    if (token == '*') {
        match('*');
        int value = lvalue * factor();
        return term_tail(value);
    } else if (token == '/') {
        match('/');
        int value = lvalue / factor();
        return term_tail(value);
    } else {
        return lvalue;
    }
}

int term() { // <factor> <term_tail>
    int lvalue = factor();
    return term_tail(lvalue);
}

int expr_tail(int lvalue) { // + <term> <expr_tail> | - <term> <expr_tail> | <empty>
    if (token == '+') {
        match('+');
        int value = lvalue + term();
        return expr_tail(value);
    } else if (token == '-') {
        match('-');
        int value = lvalue - term();
        return expr_tail(value);
    } else {
        return lvalue;
    }
}

int expr() { // <term> <expr_tail>
    int lvalue = term();
    return expr_tail(lvalue);
}

// 语法分析器 结束

int main(int argc, char *argv[]) {
    size_t linecap = 0;
    ssize_t lineLen;
    while ((lineLen = getline(&line, &linecap, stdin)) > 0) {
        src = line;
        next();
        printf("%d\n", expr());
    }
    return 0;
}




