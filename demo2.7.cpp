#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        sum += i;
    }
    cout << sum << endl;
    sum = 0;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto i : v)
    {
        sum += i;
    }
    cout << sum << endl;



    system("pause");
    return 0;
}