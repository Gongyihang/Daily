#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1010
char map[MAX][MAX], mapb[MAX][MAX];
char temp[MAX][MAX]; //记录中间图的变换，方便在递归中的回溯进行使用
int M, N, s, t;      //分别为这两个图形的长和宽
int Max, ans;        //分别记录每次遍历的最大块儿数和最终答案
bool judge(char map[][MAX], int m, int n)
{ //传入当前所搜索到的位置
    int x = m;
    int y = n;                  //x来表示行数，y来表示列数
    for (int i = 0; i < s; i++) //判断两个图是否匹配
        for (int j = 0; j < t; j++)
            if (map[x + i][y + j] != mapb[i][j])
                return false;
    return true;
}
void init_temp(int x, int y)
{ //将已经遍历过的位置标记
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            temp[i][j] = map[i][j];
    for (int i = 0; i < s; i++)
        for (int j = 0; j < t; j++)
            temp[x + i][y + j] = '0';
}
void dfs(char map[][MAX], int x, int y, int Max)
{
    if (ans < Max) //ans来记录块儿的数量
        ans = Max;
    if (x >= M)
    { //记录递归出口,走到最后一行就返回
        return;
    }
    for (int i = y; i < N; i++)
    { //对x行的每一列都进行搜索
        if (judge(map, x, i))
        {                                 //满足判断进行下一步递归 x，i这个位置开始满足小方块
            init_temp(x, i);              //把map数组复制给temp数组，且把刚刚的那一块mapb置为0
            dfs(temp, x, i + t, Max + 1); //将遍历过的位置标记，然后继续遍历（跳过刚刚裁下来的那块，继续往后遍历）截取这一块的情况
                                          //dfs完成之后又开始对map的i+1进行遍历，也就是不截取这一块的情况，截取的情况是使用另一个数组，所以没有回溯赋值
        }
    }
    dfs(map, x + 1, 0, Max); //遍历下一行
}
int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    cin >> s >> t;
    for (int i = 0; i < s; i++)
        for (int j = 0; j < t; j++)
            cin >> mapb[i][j];
    ans = 0;
    Max = 0;
    dfs(map, 0, 0, 0);
    cout << ans << endl;
    cin >> ans;
    system("pause");
    return 0;
}
