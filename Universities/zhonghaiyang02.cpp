#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;
//公众号：一航代码
vector<pair<int, int>> E[100005];
int d[10005];
int cost[10001];
int main()
{
    fill(d, d + 10005, inf);
    fill(cost, cost + 10001, 0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        E[a].push_back(make_pair(b, c));
        E[b].push_back(make_pair(a, c));
    }
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, 1)); //1是首都，1到1的cost为0，遍历从首都开始
    d[1] = 0;
    int ans = 0;
    while (!q.empty()) {
        int now = q.top().second; //得到当前路径最小的起点
        q.pop();
        for (int i = 0; i < (int)E[now].size(); i++) {
            int v = E[now][i].first; //从起点now到终点v
            if (d[v] > d[now] + E[now][i].second) {
                d[v] = d[now] + E[now][i].second;
                cost[v] = E[now][i].second; //表示到v的最短路对应要改造的铁路的最短长度为E[now][i].second，即now到v这条边的边权，
                    //因为起点到now的最短路所要改造的最短长度已经加在了now及其前面的点的cost值里了
                q.push(make_pair(-d[v], v)); //这里的处理方式很有技巧：优先选择路径小的
                    //（但是优先队列默认大顶堆，加上负号则可变成小顶堆）
            } else if (d[v] == d[now] + E[now][i].second) //最短路径相等时，优先选择花费少的
            {                                            //比如样例，在1到4的时候有两条路1-2-4和1-3-4都是7
                                                        //但是因为1-2和1-3这两条边必须建，那样选择3-4会比2-4更优一点，
                                                        //所以要判断一下。
                cost[v] = min(cost[v], E[now][i].second);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans += cost[i];
    cout << ans << endl;
    return 0;
}