#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
/*
Input：42 42 42 42 42 55 55 62 100 100 100^Z
Output:
       42 occurs 5 times
       55 occurs 2 times
       62 occurs 1 times
       100 occurs 3 times
*/
int main()
{
    int currval = 0, val = 0;
    if (cin >> currval)
    {
        int count = 1;
        while (cin >> val)
        {
            if (currval == val)
            {
                count++;
            }
            else
            {
                cout << currval << " occurs " << count << " times" << endl;
                currval = val;
                count = 1;
            }
        }
        cout << currval << " occurs " << count << " times" << endl;
    }
    system("pause");
    return 0;
}