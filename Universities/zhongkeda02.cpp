#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//这一题的意思就是，中间站有人订票但是这时这个站火车上已经有人，且总人数大于最大载客人数，则返回0。
bool solve(int m, int k, vector<int>& ans, int a, int b)
{
    if (k > m)
        return false;
    for (int i = a; i < b; i++)
        if ((ans[i] + k) > m)
            return false;
    return true;
}
int main()
{
    int n, m, a, b, k;
    while (cin >> n >> m) {
        vector<int> ans(10000000, 0); //在牛客oj上过不了，可能因为测试用例给太大了，数组开大会导致内存超限。
        while (n--) {
            cin >> a >> b >> k;
            if (solve(m, k, ans, a, b) == false) {
                cout << "0" << endl;
            } else {
                for (int i = a; i < b; i++) { //注意只有满足条件的,才进行for循环的操作
                    ans[i] += k;
                }
                cout << "1" << endl;
            }
        }
    }

    return 0;
}