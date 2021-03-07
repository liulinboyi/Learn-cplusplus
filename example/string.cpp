//
// Created by 81492 on 2021/3/6.
//
#include <iostream>
#include <string>
#include <iterator>

int main() {
    using namespace std;
    string s1; // 空字符串
    string s2("x");
    string s3("xxxxx");
    string s4("hello");
    cout << s1 << ", " << s2 << ", " << s3 << ", " << s4 << ", " << endl;

    // 迭代器 初始字符
    cout << "---------------" << endl;

    char a[] = "hello";
    string s5(begin(a), begin(a) + 2);

    cout << s5 << endl;
    // 大小相关
    // empty() // 是否为空
    // size() // 不包含最后的0字符的
    // length() // 同上
    // capacity() // 字符串已经分配的多少空间，容器大小，会自动扩容
    // reserve() // 提前申请字符容器空间减少运行时容器自动扩容的开销

    // 元素访问
    // begin() // 返回初始迭代器
    // end() // 返回结尾迭代器
    // at() //
    // [n] //
    // data() //
    // c_str() //

    cout << "---------------" << endl;

    string s6(s3.begin(), s3.end()); // 使用s3 初始s6
    cout << s6 << endl;

    cout << "at():" << endl;
    cout << s3.at(0) << s3.at(1) << s3.at(2) << s3.at(3) << endl;
    cout << "[n]:" << endl;
    cout << s3[0] << s3[1] << s3[2] << s3[3] << endl;


    cout << "获取C语言的字符串指针" << endl;
    cout << s6.c_str() << endl;


    cout << "---------------" << endl;

    cout << ("123" < "45") << endl;

    // 字符串比较 字典序比较，从两个字符开始逐一进行比较，
    // 哪个字符串先结束，他就是小的哪个，如果都没结束，那就继续比较，
    // <
    // <=
    // ==
    // !=
    // >
    // >=

    cout << "---------------" << endl;

    // 字符串插入
    // push_back(c)
    // append(...) // 末尾添加
    // insert(pos, ...) // 中间位置添加
    // += str
    string s7("a");
    s7.push_back('b');
    s7.append("c");
    s7.insert(2, "2");
    s7.pop_back();
    s7 += s2;
    cout << s7 << endl;

    cout << "---------------" << endl;

    // 删除字符串
    // assign(...) // 重新初始化为参数中的字符串
    // pop_back() // 删掉最后一个字符
    // clear() // 清空
    // erase(pos[,n]) // 传一个位置和长度，删除字符串当中的某一个部分，如果不传长度，表示从位置到结尾都删掉
    // erase(begin[,end]) // 传连个迭代器，将之间的内容都删掉
    // replace(begin, end, str) // 将begin和end之间替换成另外一个字符串
    // substr(pos[,n]) // 取子串

    // 字符串查找
    // find(str[, pos]) // 查询字符串，可以指定开始查询位置
    // find(c[, pos]) // 查询字符
    // rfind(...) // 从右边向左查询
    // find_first_of(str[, pos]) // 搜索，字符串中任意字符

    string s8("hello, 123!");
    cout << s8.find("12") << endl;
    cout << s8.find("125") << endl; // 默认返回无符号整数最大值
    cout << (s8.find("125") + 1) << endl; // 默认返回无符号整数最大值加上1就是0了

    cout << s8.find_first_of(",.!") << endl;


    cout << "---------------" << endl;


    // 字符串和数值的转换
    // stoi
    // stol
    // stoll
    // stoul
    // stoull
    // stof
    // stod
    // stold
    // to_string


    cout << "---------------" << endl;


}




