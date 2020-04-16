#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码

//进阶版判断素数
// bool isPrime(int num)
// {
//     if (num <= 3) {
//         return num > 1;
//     }
//     // 不在6的倍数两侧的一定不是质数
//     if (num % 6 != 1 && num % 6 != 5) {
//         return false;
//     }
//     for (int i = 5; i <= sqrt(num); i += 6) {
//         if (num % i == 0 || num % (i + 2) == 0) {
//             return false;
//         }
//     }
//     return true;
// }

//常规写法
// bool isPrime(int n)
// {
//     if (n <= 3) {
//         return n > 1;
//     }
//     for (int i = 2; i < n; i++) {
//         if (n % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

//假如n是合数，必然存在非1的两个约数p1和p2，其中p1<=sqrt(n)，p2>=sqrt(n)。
// bool isPrime(int n){
//     if( n <= 3){
//         return n > 1;
//     }
//     int sq = sqrt(n);
//     for(int i = 2;i <= sq;i++){
//         if(n % i == 0){
//             return false;
//         }
//     }
//     return true;
// }

bool vis[1000000]; //下标为数字，值为true则数字是素数，值为false则数字为合数
int prime[1000000]; //存储前n个素数，注意不是不超过n的素数，是前n个素数。

void init_prime(int n)
{
    fill(vis, vis + 1000000, true);
    vis[0] = vis[1] = false; //0和1不是素数
    int num = 0;
    for (int i = 2; i <= n; i++) {
        if (vis[i] == true) {
            num++;
            prime[num] = i;
        } /*判断条件意义：j<=num是保证prime[]数据存在，prime[]*i是保证数字在n的范围内*/
        for (int j = 1; (j <= num) && (i * prime[j] <= n); j++) {
            vis[i * prime[j]] = false; /*prime[]的倍数的数字肯定不是素数，将他们全部标记*/
            if (i % prime[j] == 0) {
                break;
            } /*这一步缩短了很多时间，比如i=9时，prime数组中有2，3，5，7，9*5=45，
            当i=15时，15*3再次进行了计算，
            有这步操作，可以减少很多这样类似的繁琐操作，极大的减少了时间*/
        }
    }
}

int main()
{
    init_prime(100);
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        if (vis[i]) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
