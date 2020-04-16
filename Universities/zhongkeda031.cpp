#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;
//一航代码：拓扑排序+大顶堆解决2012中科大任务调度问题
int main()
{
    int n;
    while (cin >> n) {
        getchar();
        vector<int> indegree(n, 0);
        vector<vector<int>> adjacent(n, vector<int>());
        vector<int> v;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            adjacent.push_back(v);
        }

        for (int k = 0; k < n; k++) {
            string s;
            getline(cin, s);
            int first = 0;
            bool flag = true;//flag为true时，处理第一个任务。
            for (int i = 0; i < (int)s.size(); i++) {
                if (isdigit(s[i]) && flag) {
                    first = s[i] - '0';
                    flag = false;
                } else if (isdigit(s[i]) && !flag) {
                    indegree[s[i] - '0']++;
                    adjacent[first].push_back(s[i] - '0');
                }
            }
        }

        priority_queue<int, vector<int>, greater<int>> myqueue;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                myqueue.push(i);
            }
        }

        while (!myqueue.empty()) {
            int cur = myqueue.top();
            myqueue.pop();
            res.push_back(cur);
            for (int i = 0; i < (int)adjacent[cur].size(); i++) {
                indegree[adjacent[cur][i]]--;
                if (indegree[adjacent[cur][i]] == 0) {
                    myqueue.push(adjacent[cur][i]);
                }
            }
        }
        if ((int)res.size() == n) {
            for (int i = 0; i < n - 1; i++) {
                printf("Task%d ", res[i]);
            }
            printf("Task%d\n", res[n - 1]);
        } else {
            printf("error\n");
        }
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

res:0 1 3 2

5
Task1(Task2)
Task0(Task3,Task2)
Task2(Task4)
Task4(NULL)
Task3(NULL)

res:0 1 2 3 4
*/