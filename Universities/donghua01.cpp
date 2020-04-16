#include <bits/stdc++.h>
using namespace std;

bool narcissistic(int num)
{
    int n1 = num % 10;
    int n2 = (num / 10) % 10;
    int n3 = (num / 100) % 10;
    if (n1 * n1 * n1 + n2 * n2 * n2 + n3 * n3 * n3 == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    for (int i = 100; i <= 999; i++)
    {
        if (narcissistic(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}