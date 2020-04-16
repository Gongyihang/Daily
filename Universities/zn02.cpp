#include <iostream>
using namespace std;
//@一航代码
int main()
{
    long long k, s = 0, r, c;

    while (scanf("%lld", &k) != EOF)//不可用cin会超时
    {
        r = k / 4;
        c = k % 4;
        if (c == 0)
        {
            s = 4 * r * r;
        }
        else if (c == 1)
        {
            s = 4 * r * r + 2 * r - 1;
        }
        else if (c == 2)
        {
            // s = 4 * r * r + 2 * r - 1 + 2 * r + 1;
            s = 4 * r * r + 4 * r;
        }
        else if (c == 3)
        {
            // s = 4 * r * r + 2 * r - 1 + 2 * r + 1 + 2 * r + 1;
            s = 4 * r * r + 6 * r + 1;
        }
        if (k % 2 == 0)     
        {
            printf("%lld.0\n", s / 2);//单独拿出来乘0.5会超时（存疑）
        }else{
            printf("%lld.5\n", s / 2);
        }
    }
    return 0;
}