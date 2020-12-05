#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define size1 5
const int size2 = 100;

int main()
{
    //定长一维数组声明及定义：
    int array1[10000];
    int array2[10000] = {1, 2, 3, 4, 5, 6};

    //int array3[];//非法，必须指定长度；
    //定长二维数组声明及定义：
    int array4[100][100];
    int array4_[100][100] = {{0, 0}, {0, 1}, {2, 0}};

    int array5size = 0;
    scanf("%d", &array5size);
    int array5[array5size]; //有些编译器不支持接受变量作为数组长度
    int array6[size1];
    int array6_[size2];

    //接受变量作为数组长度的一种解决方法：
    int *nums1 = (int *)malloc(array5size * sizeof(int)); //未进行初始化，数组中的值为烂值
    nums1[0] = 1;
    for (int i = 0; i < array5size; i++)
    {
        nums1[i] = 0;
        printf("%d\n", nums1[i]);
    }

    int m, n; //m是列，n是行
    scanf("%d %d", &m, &n);
    int **nums2 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        nums2[i] = (int *)malloc(n * sizeof(int));
    }

    nums2[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nums2[i][j] = 0;
            printf("%d ", nums2[i][j]);
        }
        printf("\n");
    }

    //字符
    char ch;
    //字符串
    char *s = (char*)"huihuikaoyan";//会有警告
    //字符数组
    char c1[13] = "huihuikaoyan"; //长度必须比定义的字符串长度要长，因为字符串以\0为末尾，占一个位置
    //字符串一维、二维数组
    char *c2[100];
    char *c3[100][100];

    for (int i = 0; i < (int)strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    printf("\n%s\n", c1);

    if (c1[12] == '\0')
    {
        printf("Yes\n");
    }

    system("pause");
    return 0;
}