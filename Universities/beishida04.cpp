#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
//本代码默认小驼峰命名法，如果驼峰命名法为大驼峰命名法（即第一个字母为大写）
//则须判断i是否为0,只将字符转换为小写，而不添加下划线
int main()
{
    string s1;
    cin >> s1;
    string s2;
    for (int i = 0; i < (int)s1.size(); i++) {
        if (s1[i] >= 'A' && s1[i] <= 'Z') {
            s2 += "_";
            s2 += tolower(s1[i]);
        } else if (s1[i] >= 'a' && s1[i] <= 'z') {
            s2 += s1[i];
        }
    }
    cout << s2 << endl;
    system("pause");
    return 0;
}