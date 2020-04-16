#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> count(n + 1, 1); //记录下标为boss，值为小组成员数
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        else
        {
            int k = i; //核心代码
            while (a[k] != 0)
            {                 //a[k]寻找k节点的父节点,父节点为0，则父节点是最终BOSS，根节点
                int j = a[k]; //每次向上遍历，记录节点k，的父节点，并将父节点的小组成员数加一
                count[j]++;
                k = j; //将k令成父节点，继续向上遍历
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << count[i] << " ";
    }
    cout << count[n] << endl;

    system("pause");
    return 0;
}