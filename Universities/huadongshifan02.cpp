#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

bool cmp1(string a, string b) //负数比较，长度相等则长度长的优先，
{                             //否则，按从大到小排列
    if (a.size() != b.size())
    {
        return a.size() > b.size();
    }

    {
        return a > b;
    }
}

bool cmp2(string a, string b) //正数比较，长度相等则长度短的优先
{                             //否则，按从小到大排列
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
    {
        return a < b;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> pos; //正数
    vector<string> neg; //负数
    vector<string> res; //最后结果
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        if (t[0] == '-')
        {
            neg.push_back(t.substr(1, t.size())); //存储负数，但不将负号代入
        }
        else
        {
            pos.push_back(t); //存储正数
        }
    }
    sort(neg.begin(), neg.end(), cmp1); //负数排序
    sort(pos.begin(), pos.end(), cmp2); //正数排序
    for (size_t i = 0; i < neg.size(); i++)
    {
        res.push_back("-" + neg[i]);
    }
    for (size_t i = 0; i < pos.size(); i++)
    {
        res.push_back(pos[i]);
    }
    for (size_t i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << " ";
    }
    cout << res[res.size() - 1] << endl;
    system("pause");
    return 0;
}