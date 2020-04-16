#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
struct task {
    int id;
    int pro = 0;
};
bool cmp(task a, task b) //定义任务排序规则，按照优先级高到低排序。（pro小的优先级高，pro大的优先级低）
{
    if (a.pro == b.pro) //如果优先级相等，则按照id小的排序
        return a.id < b.id;
    return a.pro < b.pro;
}

int main()
{
    int n;
    while (cin >> n) {
        getchar();
        vector<task> v(n);
        for (int i = 0; i < n; i++) { //初始化id和数组下标相等
            v[i].id = i;
        }
        for (int k = 0; k < n; k++) {
            string s;
            getline(cin, s);
            bool flag = true;
            int first;
            for (int i = 0; i < (int)s.size(); i++) {
                if (isdigit(s[i]) && flag) { //flag为true时，处理第一个任务。
                    flag = false;
                    if ((s[i] - '0') == 0) {
                        first = v[s[i] - '0'].pro + 1;
                    } else {
                        first = v[s[i] - '0'].pro;
                    } //first记录前序任务的优先级
                } else if (isdigit(s[i]) && !flag && s[i] != '0') { //后序任务的优先级等于前序任务的优先级加上自己的下标，加上自己的下标是为了和比下标小的优先级对比
                    v[s[i] - '0'].pro += (first + (s[i] - '0'));
                } else if (isdigit(s[i]) && !flag && s[i] == '0') { //对于下标为0的任务需要特殊处理一下
                    v[s[i] - '0'].pro += (first + 1);
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n - 1; i++) {
            printf("Task%d ", v[i].id);
        }
        printf("Task%d\n", v[n - 1].id);
    }
    system("pause");
    return 0;
}
/*
4
Task3(Task2)
Task0(Task3,Task2)
Task1(Task2)
Task2(NULL)
*/