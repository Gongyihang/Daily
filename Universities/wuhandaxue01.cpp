// #include <algorithm>
// #include <iostream>
// #include <math.h>
// #include <string>
// #include <vector>
// using namespace std;
// //公众号：一航代码
// int main()
// {
//     vector<int> count(10, 0);                       //计数数据
//     int a, b;
//     cin >> a >> b;
//     for (int i = a; i <= b; i++) {                  //从a到b开始遍历
//         string s = to_string(i);                    
//         for (int i = 0; i < (int)s.size(); i++) {   
//             count[s[i] - '0']++;
//         }
//     }
//     for (int i = 0; i < 9; i++) {
//         cout << count[i] << " ";
//     }
//     cout << count[9] << endl;
//     system("pause");
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//公众号：一航代码
//模板：https://www.luogu.com.cn/blog/virus2017/shuweidp
long long dp[20][20], num[20];
long long dfs(int pos, bool limit, bool lead, int dig, long long sum)
{ //limit为1表示有限制，lead为1表示有前导0
  //sum是一定需要存的一个变量，因为她表示的是操作答案，需要不断随dfs更新
    if (pos == 0)
        return sum; //边界条件
    if ((!limit) && (!lead) && (dp[pos][sum] != -1))
        return dp[pos][sum]; //记忆化
    long long ret = 0;
    int res = limit ? num[pos] : 9;//res能取到的最大值
    for (int i = 0; i <= res; i++)
        ret += dfs(pos - 1, (i == res) && limit, lead && (i == 0), dig, sum + ((i || (!lead)) && (i == dig)));
    if ((!limit) && (!lead))
        dp[pos][sum] = ret;
    return ret;
} //数位dp的操作
long long part(long long x, int d)
{
    memset(dp, -1, sizeof(dp)); //初始化
    int len = 0;
    while (x) {
        num[++len] = x % 10; //最高位在第一位
        x /= 10;
    }
    return dfs(len, 1, 1, d, 0);
}
int main()
{
    long long l, r;
    cin >> l >> r;
    for (int i = 0; i <= 9; i++) //九个digit
    {
        if (i != 9)
            cout << part(r, i) - part(l - 1, i) << " ";
        else
            cout << part(r, i) - part(l - 1, i);
    }
    return 0;
}

// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #include <math.h>
// #include <string.h>
// #include <string>
// #include <vector>
// using namespace std;
// typedef long long ll;

// int len;
// ll l, r, dp[20][20], a[20];

// ll dfs(int pos, long long sum, int dig, int lead, int limit) //记搜
// {
//     if (pos == 0)
//         return sum; //剪枝

//     if (dp[pos][sum] != -1 && (!limit) && (!lead))
//         return dp[pos][sum]; //记录当前值

//     ll ret = 0; //暂时记录当前方案数
//     int res = limit ? a[pos] : 9; //res当前位能取到的最大值

//     for (int i = 0; i <= res; i++) {
//         ret += dfs(pos - 1, sum + ((i || (!lead)) && (i == dig)), dig, (!lead) || i, (i == res) && limit);
//     }
//     if (!limit && !lead)
//         dp[pos][sum] = ret; //当前状态方案数记录
//     return ret;
// }
// ll part(ll x, int dig) //把数按位拆分
// {
//     memset(dp, -1, sizeof(dp)); //初始化-1（因为有可能某些情况下的方案数是0）
//     len = 0;
//     while (x) {
//         a[++len] = x % 10;
//         x /= 10;
//     }
//     return dfs(len, 0, dig, 1, 1); //进入记搜
// }
// int main()
// {
//     cin >> l >> r;
//     for (int i = 0; i <= 9; i++) //九个digit
//     {
//         if (i != 9)
//             cout << part(r, i) - part(l - 1, i) << " ";
//         else
//             cout << part(r, i) - part(l - 1, i);
//         //我也不知道最后边输出了空格会不会炸（手动滑稽）
//     }
//     return 0;
// }