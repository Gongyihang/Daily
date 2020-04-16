#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//@一航代码
const int inf = 99999999;//不可到达
int main()
{

    int n, m, s, t, a;
    while (cin >> n >> m >> s >> t >> a)
    {
        vector<vector<int>> e(n + 2, vector<int>(n + 2)); //邻接矩阵
        vector<int> dis(n + 2, inf);                      //保存到t点的路程
        vector<bool> visit(n + 2, false);                 //标记当前节点是否访问过
        for (int i = 1; i <= n; i++)                      //初始化二维数组，对角线被初始化为0
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    e[i][j] = e[j][i] = 0;
                }
                else
                {
                    e[i][j] = e[j][i] = inf;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int n1, n2, c;
            cin >> n1 >> n2 >> c;
            e[n1][n2] = e[n2][n1] = c;
        }

        dis[s] = 0;           //表示从出发点到i节点的距离             //Dijkstra算法部分
        int wait = 0, u = -1; //在奇数顶点等1分钟，在偶数顶点等2分钟
        for (int i = 1; i <= n; i++)
        {
            int minn = inf;
            for (int j = 1; j <= n; j++)
            {
                if (visit[j] == false && dis[j] < minn) //更新dis数组
                {
                    u = j;
                    minn = dis[j];
                }
            }
            if (u == -1) //重要，u=-1表示未找到最短路径
            {
                break;
            }
            visit[u] = true; //开始访问u顶点
            if (u % 2 == 0)  //在奇数顶点等1分钟，在偶数顶点等2分钟
            {
                wait = 2;
            }
            else
            {
                wait = 1;
            }
            for (int v = 1; v <= n; v++) //进行松弛操作的判定，注意wait
            {
                if (visit[v] == false && e[u][v] != inf && dis[u] + e[u][v] + wait < dis[v])
                {
                    dis[v] = dis[u] + e[u][v] + wait;
                }
            }
        }
        if (dis[t] <= a)
        {
            cout << "YES " << dis[t] << endl;
        }
        else if (dis[t] > a || u == -1)
        {
            cout << "KENG" << endl;
        }
    }
    return 0;
}