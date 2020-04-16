#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//@公众号：一航代码
struct person               //定义结构体保存折扣率和折扣上限
{
    double discount = 1;
    int toplimit = 0;
};

bool cmp(person a, person b)        //定义结构体排序规则，按照折扣率低的排序
{
    return a.discount < b.discount;
}

int main()
{
    int n, t;
    while (cin >> n >> t)
    {
        vector<person> v;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            person p;
            cin >> p.discount >> p.toplimit;
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp);                  //结构体排序
        for (int i = 0; i < v.size(); i++)
        {
            if (t <= v[i].toplimit)                     //若当前费用比当前折扣上限低
            {                                           //当前费用使用该折扣
                res += t * v[i].discount;
                break;
            }
            else
            {
                res += (v[i].toplimit * v[i].discount);//若当前费用比当前折扣上限高
                t -= v[i].toplimit;                    //当前折扣上限使用该折扣
                if (i == (int)v.size() - 1)            //若所有人的折扣花完，仍然不能cover费用
                {                                      //缴纳剩余原价的费用
                    res += t;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}