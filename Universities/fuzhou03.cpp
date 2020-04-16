#include <bits/stdc++.h>
using namespace std;
//公众号：一航代码
int find(int x, vector<int> &parent) //查找根节点
{
    if (x == parent[x])
    {
        return x;
    }
    parent[x] = find(parent[x], parent);
    return parent[x];
}

void unionn(int x, int y, vector<int> &parent) //合并根节点
{
    int a = find(x, parent);
    int b = find(y, parent);
    if (a < b)
    {
        parent[b] = a;
    }
    else if (a > b)
    {
        parent[a] = b;
    }
}

int main()
{
    int N, m;
    while (cin >> N)
    {
        if (N == 0)
        {
            return 0;
        }
        cin >> m;
        vector<int> parent(N + 1, -1);
        for (int i = 1; i <= N; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            unionn(a, b, parent);
        }
        int count = -1;                         //有多少个根节点
        for (int i = 1; i < parent.size(); i++) //则有根节点数量-1个道路需要修建
        {                                       //才能将所有节点连通，所以count令为-1
            if (parent[i] == i)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}