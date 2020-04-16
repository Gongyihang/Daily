#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
//此代码可在
//https://www.nowcoder.com/questionTerminal/021010dda9f04900a86738931a5600a4
//提交
//辗转相除法递归写法
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
//辗转相除法迭代写法
// int gcd(int a, int b)
// {
//     int temp;
//     if(a < b){
//         swap(a,b);
//     }
//     while(b != 0){
//         temp = a % b;
//         a = b;
//         b = temp;

//     }
//     return a;
// }

//穷举法求两数最大公约数
// int gcd(int a, int b)
// {
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;
//     int temp = (a > b) ? b : a;
//     while (a % temp == 0 || b % temp == 0) {
//         temp--;
//     }
//     return temp;
// }

//更相减损法求两数最大公约数
// int gcd(int a, int b)
// {
//     while (a != b) {
//         if (a > b) {
//             a = a - b;
//         } else if (a < b) {
//             b = b - a;
//         }
//     }
//     return a;
// }

int main()
{
    int n;
    while (cin >> n) {
        vector<int> v(n, 0);
        int mint, maxt;
        cin >> v[0];
        mint = maxt = v[0];
        for (int i = 1; i < n; i++) {
            cin >> v[i];
            if (v[i] > maxt) {
                maxt = v[i];
            }
            if (v[i] < mint) {
                mint = v[i];
            }
        }
        int gcd_res = gcd(mint, maxt);
        cout << mint << " " << maxt << " " << gcd_res << endl;
    }
    return 0;
}

