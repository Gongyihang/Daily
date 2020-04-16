#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
//http://39.105.108.26/problem.php?cid=1013&pid=2
struct MAP {
    int x, y, step;
} s, e, head, tail;
char g[100][100];
int v[100][100], f[][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }, n, m;
int bfs()
{
    memset(v, 0, sizeof(v));
    queue<struct MAP> q;
    q.push(s);
    s.step = 0;
    v[s.x][s.y] = 1;
    while (!q.empty()) {
        head = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            tail.x = head.x + f[i][0];
            tail.y = head.y + f[i][1];
            tail.step = head.step + 1;
            if (!v[tail.x][tail.y] && g[tail.x][tail.y] != '#' && tail.x >= 0 && tail.x < n && tail.y >= 0 && tail.y < m) {
                if (tail.x == e.x && tail.y == e.y)
                    return tail.step;
                v[tail.x][tail.y] = 1;
                q.push(tail);
            }
        }
    }
    return -1;
}
int main()
{
    int t, i, j;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> g[i][j];
                if (g[i][j] == 'S') {
                    s.x = i;
                    s.y = j;
                } else if (g[i][j] == 'E') {
                    e.x = i;
                    e.y = j;
                }
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}

// #include <algorithm>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <iostream>
// #include <math.h>
// #include <queue>
// #include <stack>
// #include <string>
// using namespace std;
// //http://39.105.108.26/problem.php?cid=1013&pid=2
// #define INF 9999999999
// int a[2501][2501];
// int dis[2501];
// int vis[2501];
// int t, n, s, e;
// void dij(int x, int y)
// {
//     for (int i = 1; i <= t; i++) {
//         dis[i] = a[s][i];
//         vis[i] = 0;
//     }
//     vis[x] = 1;
//     int k;
//     k = -1;
//     int minn;

//     for (int i = 1; i <= t; i++) {
//         minn = INF;
//         for (int j = 1; j <= t; j++) {
//             if (vis[j] == 0 && minn > dis[j]) {
//                 minn = dis[j];
//                 k = j;
//             }
//         }
//         if (k == -1) {
//             return;
//         }
//         vis[k] = 1;
//         for (int j = 1; j <= t; j++) {
//             if (vis[j] == 0 && dis[k] + a[k][j] < dis[j]) {
//                 dis[j] = dis[k] + a[k][j];
//             }
//         }
//     }
//     printf("%d\n", dis[y]);
// }
// int main()
// {

//     cin >> t >> n >> s >> e;
//     int t1, t2, c;
//     for (int i = 1; i <= t; i++) {
//         for (int j = 1; j <= t; j++) {
//             a[i][j] = INF;
//         }
//     }
//     // memset(a, INF, sizeof(a));
//     //memset(vis,0,sizeof(vis));
//     for (int i = 1; i <= n; i++) {
//         cin >> t1 >> t2 >> c;
//         if (c < a[t1][t2]) {
//             a[t1][t2] = a[t2][t1] = c;
//         }
//     }
//     dij(s, e);
//     // system("pause");
//     return 0;
// }
//当t很大时，用floyd时间超限
// const int maxn = 2505;
// #define INF 0x3f3f3f
// int a[maxn][maxn];
// int vis[maxn];
// int dis[maxn];
// int t, n, s, e;

// void fl()
// {

//     for (int k = 1; k <= t; k++)
//     {
//         for (int i = 1; i <= t; i++)
//         {
//             if (a[i][k] != INF) //*不要忘记这个判断
//             {
//                 for (int j = 1; j <= t; j++)
//                 {
//                     if (a[i][j] > a[i][k] + a[k][j])
//                     {
//                         a[i][j] = a[i][k] + a[k][j];
//                     }
//                 }
//             }
//         }
//     }
//     printf("%d\n", a[s][e]);
// }
// int main()
// {

//     cin >> t >> n >> s >> e;
//     int t1, t2, c;
//     memset(a, INF, sizeof(a));
//     //memset(vis,0,sizeof(vis));
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> t1 >> t2 >> c;
//         if (c < a[t1][t2])
//         {
//             a[t1][t2] = a[t2][t1] = c;
//         }
//     }
//     fl();
//     return 0;
// }