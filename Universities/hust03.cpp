#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*
程序逻辑分为两个部分：
第一部分模拟除法运算，
每进行一步除法运算，
都需要将当前得到的商和余数，
分别保存在数组中，
并且交给第二部分进行循环检测；

第二部分将传递进来的商和余数，
和保存在数组中的历史商和余数依次比较，
若不相等，告知第一部分继续进行除法运算，
若相等，则记录当前商所在下标，该下标为循环节起始位置，
直到数组结束为循环节结束。​
@公众号：一航代码
*/
int pos = 0;

//寻找循环节，当前余数和商和之前保存的余数和商相等时找到循环节，循环节起始位置为pos
bool find(vector<int> rem, vector<int> dec, int r, int c)
{
    for (int i = 0; i < dec.size(); i++)
    {
        if (rem[i] == r && dec[i] == c)
        {
            pos = i;
            return false;
        }
    }
    return true;
}
//模拟除法运算
void repetend(int n, int d)
{
    string fp = to_string(n / d) + "."; //整数部分
    if (n > d)                          //第一次除法
    {
        n = n % d;
    }
    int r, c; //r是余数，c是商
    c = n * 10 / d;
    r = (n * 10) % d;

    vector<int> rem, dec; //rem是商数组保存之前的商，dec是余数数组保存之前的余数
    bool flag = true;
    while (find(rem, dec, r, c))
    {
        dec.push_back(c);
        rem.push_back(r);
        r *= 10;
        c = r / d;
        r %= d;
        if (c == 0)
        {
            flag = false; //flag为true为循环小数，flag为false为不循环小数
            break;
        }
    }

    cout << fp;
    for (int i = 0; i < pos; i++)
    {
        cout << dec[i];
    }

    for (int i = pos; i < dec.size(); i++)
    {
        if (i == pos && flag)
        {
            cout << "(";
        }
        cout << dec[i];
        if (i == dec.size() - 1 && flag)
        {
            cout << ")";
        }
    }
    cout << endl;
}

int main()
{
    int n1, n2, n3, n4, d1, d2, d3, d4;
    scanf("%d/%d %d/%d %d/%d %d/%d", &n1, &d1, &n2, &d2, &n3, &d3, &n4, &d4);

    repetend(n1, d1);
    repetend(n2, d2);
    repetend(n3, d3);
    repetend(n4, d4);

    system("pause");
    return 0;
}