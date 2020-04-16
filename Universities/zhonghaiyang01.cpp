#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    int year, number;
    cin >> year >> number;
    //一三五七八十腊，三十一天永不差，除了2月平年28天，闰年29天。其他月份为30天
    int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    //能被4整除但不能被100整除的年份或者能被400整除的年份为闰年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        a[2] = 29;
    }

    int month = 1, day = 0;
    while (number > 0) {
        number -= a[month];
        month++;
    }

    day = number + a[--month];
    cout << month << endl
         << day << endl;
    system("pause");
    return 0;
}