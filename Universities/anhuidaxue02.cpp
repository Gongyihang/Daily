#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

bool isperfect_number(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main()
{

    for (int i = 1; i < 1000; i++) {
        if (isperfect_number(i)) {
            cout << i << endl;
        }
    }
    system("pause");
    return 0;
}