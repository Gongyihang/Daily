#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int num[11][11];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { //行
        for (int j = 0; j < n; j++) { //列
            cin >> num[i][j];
        }
    }

    for (int i = 0; i < n; i++) {           //按行遍历，矩阵元素向左走
        int max = i;                        //假设最大数在第一行
        for (int k = i; k < n; k++) {       //按列遍历，矩阵元素向下走
            if (num[k][i] > num[max][i]) {  
                max = k;                    //记录最大数所在的行
            }
        }
        int t[10];
        for (int j = 0; j < n; j++) {       //最大数所在的行元素与当前的第i行元素进行交换
            t[j] = num[i][j];
            num[i][j] = num[max][j];
            num[max][j] = t[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}