#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    int s = 1, sum = 0, n;
    cin >> n;
    for (int i = 1; i < n+1; i++) {
        s *= i;
        s %= 1000000;
        sum += s;
    }
    sum %= 1000000;
    cout << sum << endl;
    system("pause");
    return 0;
}