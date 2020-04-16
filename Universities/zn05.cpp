#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//公众号@一航代码
int main()
{
    string s;
    while (cin >> s)
    {
        vector<int> num(10, 0);
        int max_num = 0, n = 10;
        for (int i = 0; i < s.size(); i++)
        {
            int t = s[i] - '0';
            num[t]++;
            if (num[t] > max_num)       //若当前数字出现次数最大
            {                           //更新最大次数和数字
                max_num = num[t];
                n = t;
            }
            else if (num[t] == max_num)//如果当前数字出现次数和最大次数相等
            {                          //保留数字更小的那个
                if (t < n)
                {
                    n = t;
                }
            }
        }
        cout << n << endl;
    }
    return 0;
}