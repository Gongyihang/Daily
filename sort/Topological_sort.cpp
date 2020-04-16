#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
//拓扑排序快速上手之Leetcode 207.课程表
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> indegrees(numCourses, 0);//统计课程安排图中每个节点的入度，生成入度表
        vector<vector<int>> adjacency(numCourses);//邻接矩阵
        vector<int> v;
        for (int i = 0; i < numCourses; i++) {//初始化numCourse个顶点，不初始化不可用数组形式进行访问
            adjacency.push_back(v);
        }
        for (int i = 0; i < (int)prerequisites.size(); i++) {//构建邻接矩阵，统计节点的入度，并将节点push进邻接矩阵
            indegrees[prerequisites[i][0]]++;//[0,1]表示1是0的前置课程，这里的[i,0]是后置课程
            adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]);//将0课程节点指向1课程节点
        }

        queue<int> myqueue;                     //队列保存当前访问的课程节点
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {            //如果课程节点入度为0，则将其入队。
                myqueue.push(i);
            }
        }
        while (!myqueue.empty()) {              //依次访问课程节点入度为0的节点，直到队列为空
            int temp = myqueue.front();         //取队头课程节点
            myqueue.pop();                      //出队
            numCourses--;                       //计数--
            for (int i = 0; i < (int)adjacency[temp].size(); i++) {//访问当前课程节点的邻接课程节点
                indegrees[adjacency[temp][i]]--;                   //因为当前课程节点已经出队，后继节点的入度减1
                if (indegrees[adjacency[temp][i]] == 0) {          //如果后继节点的入度为为0，则将其入队
                    myqueue.push(adjacency[temp][i]);
                }
            }
        }
        return 0 == numCourses;
    }
};

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = { { 1, 0 }, { 0, 1 } };
    Solution s;
    bool res = s.canFinish(numCourses, prerequisites);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
