#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    //字符串转数字
    string s = "100";
    int num1 = stoi(s);

    cout << num1 << endl;

    s = "100.111";
    double num2 = stod(s);

    cout << num2 << endl;

    //数字转字符串
    string s1 = to_string(100);
    cout << s1 << endl;
    string s2 = to_string(100.111);
    cout << s2 << endl;

    //string类型转为const char*类型用printf输出
    auto s3 = s2.c_str();
    printf("%s\n",s3);


    //大小写字符转换,大小小大，大写字母的ASCII值小，小写字母的ASCII值大
    string s4 = "A";
    s4[0] += ('a'- 'A');
    cout<<s4<<endl;

    system("pause");
    return 0;
}