//
// Created by 81492 on 2021/3/2.
//
#include <iostream>

// 定义结构体
struct StudentInfo1 {
    char name[20]; // 字符数组表示字符串
    int age;
    double score;
};

void use1() {
    using namespace std;
    // 使用结构体
    StudentInfo1 sz = {"张三", 24, 90};
    StudentInfo1 ls = {"李四"}; // 后面未赋值，则自动用0填充
    ls.age = 26;
    ls.score = 80;

    cout << "name: " << ls.name << "\t" << "age: " << ls.age << "\t" << "score: " << ls.score << std::endl;
    cout << "name: " << sz.name << "\t" << "age: " << sz.age << "\t" << "score: " << sz.score << std::endl;
}

struct StudentInfo2 {
    char name[20]; // 字符数组表示字符串
    int age;
    enum Gender {
        MALE, // 男
        FEMALE, // 女
    } gender;
    union Score {
        int sit_up_times; // 仰卧起坐
        double throwing_distance; // 推铅球距离
    } score;
};

void printStudent(StudentInfo2 student) {
    using namespace std;
    if (student.gender == StudentInfo2::Gender::MALE) {
        cout << "name: " << student.name << "\t" << "age: " << student.age << "\t" << "Gender: " << student.gender
             << "\t" << "score（推铅球距离）: "
             << student.score.throwing_distance
             << std::endl;
    } else if (student.gender == StudentInfo2::Gender::FEMALE) {
        cout << "name: " << student.name << "\t" << "age: " << student.age << "\t" << "Gender: " << student.gender
             << "\t" << "score（仰卧起坐）: "
             << student.score.sit_up_times
             << std::endl;
    };
}

void use2() {
    using namespace std;
    StudentInfo2::Score zss = {.throwing_distance =  160};  // 距离
    StudentInfo2::Score lss = {.sit_up_times =  60}; // 次数
    // 使用结构体
    StudentInfo2 zs = {"张三", 24, StudentInfo2::MALE, zss}; // 男 => 推铅球距离
    StudentInfo2 ls = {"李四"}; // 后面未赋值，则自动用0填充
    ls.age = 26;
    ls.score = lss;
    ls.gender = StudentInfo2::FEMALE; // 女 => 仰卧起坐

    printStudent(zs);
    printStudent(ls);
}

int main() {

    use2();

    // 定义

    return 0;
}







