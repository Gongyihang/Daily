#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
bool cmp(char a, char b)
{
    return a > b;
}

int main()
{
    int num;
    scanf("%d", &num);
    // if (num % 1111 == 0 || num == 0) {
    //     printf("%04d - %04d = 0000", num, num);
    //     return 0;
    // }
    // if (num == 6174) { //测试点5
    //     printf("7641 - 1467 = 6174");
    //     return 0;
    // }
    int res = num, num1, num2;
    while (1) {
        string t = to_string(res);
        t.insert(0, 4 - t.size(), '0'); //测试点2、3、4//重要，样例1110
        sort(t.begin(), t.end());
        num1 = stoi(t);
        sort(t.begin(), t.end(), cmp);
        num2 = stoi(t);
        res = num2 - num1;
        printf("%04d - %04d = %04d\n", num2, num1, res);
        if (res == 6174 || res == 0) {
            break;
        }
    }
    system("pause");
    return 0;
}