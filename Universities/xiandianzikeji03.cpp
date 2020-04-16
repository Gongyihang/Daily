#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
struct point {
    int x = 0;
    int y = 0;
};

struct rec {
    point p1;
    point p2;
};

int main()
{
    int n;
    vector<vector<int>> map(101, vector<int>(101, 0));
    vector<rec> r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        rec t;
        cin >> t.p1.x >> t.p1.y >> t.p2.x >> t.p2.y;
        r.push_back(t);
    }
    int count = 0;
    for (int k = 0; k < (int)r.size(); k++) {
        for (int i = r[k].p1.x + 1; i <= r[k].p2.x; i++) {
            for (int j = r[k].p1.y + 1; j <= r[k].p2.y; j++) {
                if (map[i][j] == 0) {
                    map[i][j] = 1;
                    count++;
                } else {
                    continue;
                }
            }
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}