#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*
输入样例：
EEEEAAAASSSSSYYY
EAESY
SEoAtSNY
easy
eAsy
输出：
easy
easy
difficult
difficult
difficult
@一航代码
*/

bool match(string s)
{
    if (s.size() > 1000)
    {
        return false;
    }
    string cmp = "EASY";
    for (int i = 0, j = 0; i < s.size();)
    {
        if (s[i] == cmp[j])
        {
            j++;
            i++;
            if (j == (int)cmp.size())
            {
                return true;
            }
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (match(s))
        {
            cout << "easy" << endl;
        }
        else
        {
            cout << "difficult" << endl;
        }
    }
    return 0;
}