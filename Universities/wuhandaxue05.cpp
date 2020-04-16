#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码

int main()
{
    string a, b;
    cin >> a >> b;
    int flag = 0;             //进位
    string c;
    if (a.size() < b.size()) {//保证a是最大的数字
        swap(a, b);
    }
    auto ita = a.end() - 1;
    for (auto itb = b.end() - 1; itb != b.begin() - 1; ita--, itb--) {//从后往前遍历相加
        int sum = (*ita - '0') + (*itb - '0') + flag;
        flag = 0;                           //重置进位
        if (sum >= 10) {
            flag = 1;
        }
        c += to_string(sum % 10);
    }

    for (; ita != a.begin() - 1; ita--) {
        int sum = (*ita - '0') + flag;      //对a进行和进位的相加，譬如有999999 + 1
        flag = 0;                           //重置进位
        if (sum >= 10) {
            flag = 1;
        }
        c += to_string(sum % 10);
    }
    if (flag == 1) {                        //如果a存在进位，譬如99+1，最后有进位1
        c += '1';
    }
    reverse(c.begin(), c.end());            //反转结果
    cout << c << endl;
    system("pause");
    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;
// //公众号：一航代码
// int main()
// {
//     string a, b, c;
//     string res;
//     cin >> a >> b;
//     int carry = 0;
//     int len1 = a.size() - 1;
//     int len2 = b.size() - 1;
//     res = "";
//     while (len1 >= 0 || len2 >= 0) {
//         int i = len1 >= 0 ? a[len1--] - '0' : 0; //从最后一位开始相加，不够的补0
//         int j = len2 >= 0 ? b[len2--] - '0' : 0;
//         int sum = i + j + carry;
//         carry = sum / 10; //进位
//         res = to_string(sum % 10) + res;
//     }
//     if (carry) { //如果最高位有进位，加上
//         res = '1' + res;
//     }
//     cout << res << endl;
// }
