#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码 进阶版判断素数
bool isPrime(int num)
{
    if (num <= 3) {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
