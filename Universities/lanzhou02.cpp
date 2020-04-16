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
    if (s.size() == 1)
    {
        cout << s << endl;
        return 0;
    }
    s += '\n'; //增加一个回车标志位表示结束，前一个字符不可能与它相等
    int count = 1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        else if (s[i] != s[i + 1] && count != 1)
        {
            cout << s[i] << count;
            count = 1;
        }
        else if (s[i] != s[i + 1] && count == 1)
        {
            cout << s[i];
            count = 1;
        }
    }
    return 0;
}