#include <cstring>
#include <iostream>
#include <queue>
#define MAX 100000001
#define N 205
using namespace std;
//公众号：一航代码
typedef long long int LL;
int d[N][N];
bool vis[N][N];
bool arcs[N][N];
struct Point {
    int x, y;
} p[N];
//des_p是destination point的缩写，表示目的地点
//ap_num是added point number的缩写，表示通过的增设点的数量
struct P_D {
    int des_p;
    int ap_num;
};
int m, n, k, r;
queue<P_D> q;
void spfa()
{
    memset(d, MAX, sizeof(d));
    struct P_D s;
    struct P_D temp;
    s.des_p = 0;
    s.ap_num = 0;
    q.push(s);
    vis[0][0] = 1;
    d[0][0] = 0;
    while (!q.empty()) {
        s = q.front();
        q.pop();
        vis[s.des_p][s.ap_num] = 0;
        for (int i = 0; i < n + m; i++) {
            //和s点相连的点
            if (arcs[s.des_p][i]) {
                temp.des_p = i;
                temp.ap_num = s.ap_num;
                if (i >= n) {
                    temp.ap_num++;
                }
                //松弛操作
                if (temp.ap_num <= k && d[temp.des_p][temp.ap_num] > d[s.des_p][s.ap_num] + 1) {
                    d[temp.des_p][temp.ap_num] = d[s.des_p][s.ap_num] + 1;
                    if (!vis[temp.des_p][temp.ap_num]) {
                        //是起点所到目的地点和经过的增设点数进入队列 
                        vis[temp.des_p][temp.ap_num] = 1;
                        q.push(temp);
                    }
                }
            }
        }
    }
    int ans = MAX;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, d[1][i]);
    }
    cout << ans - 1;
}

int main()
{
    //存在的点和可放置的点
    cin >> n >> m >> k >> r;
    for (int i = 0; i < n + m; i++) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 0; i < n + m; i++) {
        for (int j = i + 1; j < n + m; j++) {
            if ((LL)(p[i].x - p[j].x) * (p[i].x - p[j].x) + (LL)(p[i].y - p[j].y) * (p[i].y - p[j].y) <= (LL)r * r) {
                arcs[i][j] = arcs[j][i] = 1;
            }
        }
    }
    spfa();
    return 0;
}