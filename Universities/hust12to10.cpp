#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int res = 0;                //存十进制结果
    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - '0'; //将字符转化为数字
        if (isdigit(s[i]))
        {
            cout << s[i];
            res += (num * pow(12, s.size() - i - 1));
        }
        else if (s[i] == 'a')
        {
            cout << 10;
            res += (10 * pow(12, s.size() - i - 1));
        }
        else if (s[i] == 'b')
        {
            cout << 11;
            res += (11 * pow(12, s.size() - i - 1));
        }
        if (i != s.size() - 1)                      //i!=s.size()-1是为了控制输出空格隔开，并且后面没有多余的空格
        {                           
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }

    cout << res << endl;

    vector<int> bin(32, 0);
    int i = 31;
    while (res / 2 != 0) //将十进制转换为二进制数
    {
        bin[i] = res % 2;
        res /= 2;
        i--;
    }
    bin[i] = res;
    for (int i = 0; i < 32; i++) //控制输出
    {
        cout << bin[i];
        if ((i + 1) % 8 == 0)
        {
            cout << " ";
        }
    }

    system("pause");
    return 0;
}