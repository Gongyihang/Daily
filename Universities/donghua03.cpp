#include <iostream>
using namespace std;
#define MAX_TREE_SIZE 100
//公众号：一航代码
typedef struct
{
    char data;  //结点数据域
    int parent; //结点双亲在数组中的位置
} PTNode;
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE]; //存储树中所有的结点
    int n;                       //树中的结点数，n不超过100
} PTree;
/*
算法思想：遍历结点数组，当该结点的序号有另外一个节点指向时，
那么该结点为非叶节点，当遍历完结点时，
没有一个结点的指针指向该序号的话，那么该结点即是叶结点。
*/

//返回树中叶结点的个数
int GetLeavesCount(PTree T)
{
    int count = 0; //转换一下思考方式，我们统计非叶子节点个数，然后用总结点数减去非叶子结点数
    for (int i = 0; i < T.n; i++)
    {                                     //也就是说我们去找i节点有没有孩子节点是j
        for (int j = i + 1; j < T.n; j++) //并且对双亲表示法而言，j的孩子下标一定比i大，所以初值设为i+1
        {
            if (T.nodes[j].parent == i)
            {
                count++;
                break;
            }
        }
    }
    return T.n - count;
}
int main()
{
    cout << "Please enter the number of nodes:" << endl;
    int n = 0;
    cin >> n;
    PTree pt;
    pt.n = n;
    cout << "Please enter the data and the position of parent:" << endl;
    for (int i = 0; i < n; i++)
    { //输入结点的数据域和结点双亲在数组中的位置
        cin >> pt.nodes[i].data >> pt.nodes[i].parent;
    }
    int leaves = GetLeavesCount(pt);
    cout << leaves << endl;
    system("pause");
    return 0;
}