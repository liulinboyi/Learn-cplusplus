//
// Created by 81492 on 2021/3/2.
//

#include <iostream>

struct Date {
    int year;
    int month;
    int day;

    void printConst() const {
        using namespace std;
//        year = 12;
        cout << year << '-' << month << '-' << day << endl;
    };

    void printVar() {
        using namespace std;
        year = 2022;
        cout << year << '-' << month << '-' << day << endl;
    }
};

int main() {
    Date date = {
            2021,
            3,
            2
    };
    date.printConst();
}
















