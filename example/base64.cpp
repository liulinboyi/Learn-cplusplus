//
// Created by 81492 on 2021/3/8.
//

// [丢人了，我居然不知道 Base64 编码的原理 | 程序员黄玄 Vol.003](https://www.bilibili.com/video/BV1xy4y187MF)
// 将任何二进制数据都编码为ASCII纯文本字符串
// 这样就可以在任何兼容ASCII纯文本的地方，完好无损的传输文件
// 不用担心文件因为编解码的原因被损坏
// 为了在ASCII纯文本协议中传输，采用了ASCII的一个包含64（Base64中64由来）个字母（可显示字符）的子集，重新排了一张表

// eg:
// 01001000 01010101 01011000 // 原始数据
// 编码
//  => Base64 ?

// 64 > 2^6 > 6位一组，示例二进制数据能被6整除

//   01001000 01010101 01011000  // 3 * 8 // 原始数据
// 010010 00010101 010101 011000 // 4 * 6
//   18      05      21     24   // 十进制
//    S      F        V      Y   // 子集编码查询结果，都在ASCII中，可以作为纯文本来传输了

//   083     070     086    089  // As ASCII，去原ASCII，完整的ASCII，查询所得
// 01010011 01000110 01010110 01011001 // 去原ASCII，完整的ASCII，查询所得，
//                            ^^^^^^^^ -> 这里多出一个byte，Base64编码会带来，大约1/3的额外体积开销

// 解码
// => Binary ?
//    S      F        V      Y // 用编码结果，反着去子集查即可
//    18      05      21     24
// 010010 00010101 010101 011000
//   01001000 01010101 01011000
//     072     085       088
//      H       U         X

//    H         X
//   072       088
// 01001000  01011000 // 2 * 8
// 二进制数据不能被6整除
// 010010 000101 1000 <- 不能被6整除
// 010010 000101 100000 <- 先补0，成为6的倍数
//   18     05     32
//    S      F      g        // 非填充，的编码结果，但是大部分编码器会使用填充的编码结果
//    S      F      g    =  // 但是大部分编码器会使用填充的编码结果，最后加一个=作为pending，使输出长度可以是4的倍数
#include <iostream>

using namespace std;
string base64Chars("ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghigklmnopqrstuvwxyz0123456789+/");

int decode(uint8_t c) {
    int out = base64Chars.find(c);
    // out == -1
    if (out + 1 == 0) {
        throw invalid_argument("Invalid base64 input!Please check!");
    }
    return out;
}

string base64Decode(const string_view input) {
    string output;
    unsigned buf = 0; // 缓冲区
    unsigned bufSize = 0;

    for (uint8_t c : input) {
        if (c == '=') { // 默认等号总是在末尾，跳出循环
            break;
        }
        int sextet = decode(c); // 只可能在0-63之间（0b111111二进制十进制为63），只需要低六位
//        cout << sextet << endl;
        // 这个例子
        //
        // buf: 0000 0000 0000 0000 // S -> 18; bufSize -> 6; buf << 6 左移6位
        // buf: 0000 0000 0001 0010 // buf + 18 => 18(十进制)
        // buf: 0000 0100 1000 0000 // F -> 5; bufSize -> 12; buf << 6 左移6位
        // buf: 0000 0100 1000 0101 // buf + 5 => 1157(十进制)
        // bufSize -> 12 > 8 => buf: 0000 0100 1000 0101 // buf >> 4 右移四位 => 0000 0000 0100 1000 => 0100 1000 => char (72(十进制)) // 正好8位，一个byte，此时buf只是计算了下位移的值，buf本身的值并没有改变
        // 同上


        // buf: 0000 0000 0011 1111 (63); sextet: 0011 1111(63);
        // buf: 0000 1111 1100 0000 // buf << 6
        // buf: 0000 1111 1111 1111 // buf + sextet

        buf = (buf << 6) + sextet;
        bufSize += 6;
        if (bufSize >= 8) {
            // buf: 0000 1111 1111 1111; bufSize: 12;
            // buf: 0000 0000 1111 1111; // buf >> 4
            // push_back: 1111 1111; // (char) buf
            output.push_back(char(buf >> (bufSize - 8))); // 右移4位
            bufSize -= 8;
        }
    }
    return output;
}

int main() {

    using namespace std;
    cout << "atob: " << base64Decode("SFVY").c_str() << endl;
    cout << "atob: " << base64Decode("SFg").c_str() << endl;
    cout << "atob: " << base64Decode("SFg=").c_str() << endl;
    cout << "atob: " << base64Decode("Nah!").c_str() << endl;

}



























