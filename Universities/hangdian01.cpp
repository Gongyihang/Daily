#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//进阶版判断素数
bool isPrime(int num)
{
    if (num <= 3)
    {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5)
    {
        return false;
    }
    for (int i = 5; i <= sqrt(num); i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int guan, em[4], lose = 0;
    cin >> guan;
    for (int i = 1; i <= 3; i++)
    {
        cin >> em[i];
    }
    for (int i = 1; i <= 3; i++)
    {
        int res = (guan - em[i]) * (guan - em[i]) + (guan - em[i]) + 41;
        if (isPrime(res))
        {
            continue;
        }
        else
        {
            lose = i;
            printf("Guan Yu lost to the No.%d enemy.", lose);
        }
    }
    if (lose == 0)//lose没发生改变过，则三局全获胜
    {
        printf("WIN\n");
    }
    return 0;
}
