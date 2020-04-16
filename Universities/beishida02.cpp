#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;                                     //若oj需要循环输入，此处须用循环
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for (int i = n; i >= 1; i--) {                 //d[i][j]表示第i棵树间隔j个距离，值表示非递减序列的长度
        for (int j = 1; j <= n; j++) {             //从第n棵树，依次向前遍历 
            if ((i - j) >= 1 && v[i] >= v[i - j]) {//遍历与第i棵树，距离为j个单位的树，如果第i-j棵树的高度比第i棵树小则更新dp数组
                dp[i - j][j] = dp[i][j] + 1;
            }
        }
    }
    int max_tree = 1;
    // int index,gap;
    max_tree = dp[1][1];
    for (int i = 1; i <= n; i++) {                  //取dp数组中的最大值max_tree，即为最长非递减序列的长度
        for (int j = 1; j <= n; j++) {              //if中可添加标记，index为序列起点，gap为间隔
            if (max_tree <= dp[i][j]) {             //这里添加了等号，如果有多种情况，仅保留最后一个最大值
                max_tree = dp[i][j];                //也可以定义一个res数组保存多种情况下的序列
                // index = i;
                // gap = j;
            }
        }
    }

    cout << n - max_tree << endl;                   //砍掉的树为n-max_tree
    system("pause");
    return 0;
}