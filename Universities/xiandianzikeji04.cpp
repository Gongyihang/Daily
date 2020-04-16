#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
struct scores {
    int time;
    int score;
};

bool cmp(scores a, scores b)
{
    if (a.score == b.score) {
        return a.time < b.time;
    }
    return a.score > b.score;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<scores> v;
    for (int i = 0; i < n; i++) {
        int year, month, day;
        scores s;
        scanf("%d/%d/%d %d", &year, &month, &day, &s.score);
        s.time = year * 10000 + month * 100 + day;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < (int)v.size(); i++) {
        printf("%d/%d/%d %d\n", v[i].time / 10000, v[i].time % 10000 / 100, v[i].time % 100, v[i].score);
    }
    system("pause");
    return 0;
}