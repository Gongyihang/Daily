#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

//法一：字符串解法
// int main()
// {
//     string s1, s2;
//     cin >> s1;
//     s1 = s2;
//     reverse(s1.begin(), s1.end());
//     if (s1 == s2) {
//         cout << "true" << endl;
//     } else {
//         cout << "false" << endl;
//     }
//     system("pause");
//     return 0;
// }

//法二：取余取模
//判断是否是回文数,数据范围(10,1000)
bool isCycleNum(int n)
{
    int a[9] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    //若是十位数，则直接采用数组里面的进行匹配
    for (int i = 0; i < 9; i++)
        if (a[i] == n)
            return true;
    //若是百位数
    int ge = n % 10;
    int bai = n / 100;
    if (ge == bai)
        return true;
    return false;
}
int main()
{
    //判断输入的数据是否合法省去
    int n = 0;
    cin >> n;
    if (isCycleNum(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    system("pause");
    return 0;
}
