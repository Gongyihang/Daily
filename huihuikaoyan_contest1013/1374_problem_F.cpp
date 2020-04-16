#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
//http://39.105.108.26/problem.php?cid=1013&pid=5
vector<vector<int>> v(100001);
vector<int> st(100001);

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int p;
    cin >> p;
    st[p] = 1;
    int res = -1, count = 1, len, temp;
    while (++res, count) {
        for (int i = 1; i <= n; i++) {
            if (st[i] == 1) {
                len = v[i].size();
                for (int j = 0; j < len; j++) {
                    temp = v[i][j];
                    if (!st[temp]) //不免疫
                    {
                        st[temp] = 3; //患上流感
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (st[i] == 2) {
                st[i] = 0;
            } else if (st[i] == 1) {
                st[i] = 2;
                --count; //痊愈，流感人数减少
            } else if (st[i] == 3) {
                st[i] = 1;
                ++count; //传染，流感人数增加
            }
        }
    }
    cout << res;
    // system("pause");
    return 0;
}