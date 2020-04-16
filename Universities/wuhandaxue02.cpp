#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int last_num(int n)
{
    for (int i = 1, j = n; j > 0; i++, j--) {       //计算最大数
        n += i;
    }
    return n;
}

int main()
{
    int n;
    scanf("%d", &n);
    int num = 1;
    char ch = ' ';
    for (int i = 1; i <= n; i++) {                  
        int width = to_string(last_num(n)).size();  //计算三角形最大数的长度，为后面输出格式做准备
        for (int j = n - i; j > 0; j--) {
            printf("%*c", width + 1, ch);           //*代表width+1
        }
        for (int k = 1; k < i; k++) {
            printf("%*d ", width, num++);           //*代表width
        }
        printf("%*d\n", width, num++);              //*代表width
    }
    system("pause");
    return 0;
}