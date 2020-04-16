#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

struct person
{
    string id = "";
    int ts = 0, te = 0;
    int worktime;
};

bool cmps(person a, person b)   //最早上班
{
    return a.ts < b.ts;
}
bool cmpe(person a, person b)   //最晚下班
{
    return a.te > b.te;
}
bool cmpl(person a, person b)   //上班时间最久
{
    return a.worktime > b.worktime;
}

int main()
{
    int n;
    cin >> n;
    vector<person> p;
    for (int i = 0; i < n; i++)
    {
        person t;
        int tsh, tsm, tss, teh, tem, tes;
        cin >> t.id;
        scanf("%d:%d:%d %d:%d:%d", &tsh, &tsm, &tss, &teh, &tem, &tes);
        t.ts = tsh * 3600 + tsm * 60 + tss;     //统一尺度
        t.te = teh * 3600 + tem * 60 + tes;
        t.worktime = t.te - t.ts;
        p.push_back(t);
    }

    sort(p.begin(), p.end(), cmps);
    cout << p[0].id;
    printf(" %02d:%02d:%02d\n", p[0].ts / 3600, (p[0].ts % 3600) / 60, (p[0].ts % 3600) % 60);

    sort(p.begin(), p.end(), cmpe);
    cout << p[0].id;
    printf(" %02d:%02d:%02d\n", p[0].te / 3600, (p[0].te % 3600) / 60, (p[0].te % 3600) % 60);

    sort(p.begin(), p.end(), cmpl);
    cout << p[0].id;
    printf(" %02d:%02d:%02d\n", p[0].worktime / 3600, (p[0].worktime % 3600) / 60, (p[0].worktime % 3600) % 60);

    system("pause");
    return 0;
}