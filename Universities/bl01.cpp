#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
/*
341181198809150011
11010119900307387X
150102199003075131
1222222222
111111111111111111​11
150102200003075131

Corrent ID
Corrent ID
Corrent ID
Wrong ID
Wrong ID
Wrong ID
@公众号：一航代码
*/

int main()
{
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    string s;
    while (cin >> s)
    {
        if (s.size() != 18)
        {
            cout << "ID Wrong" << endl;
            continue;
        }
        char y[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
        int sum = 0, x = 0;
        for (int i = 0, j = 0; i < s.size(); i++,j++)
        {
            sum += ((s[i] - '0') * weight[i]);
        }
        x = sum % 11;
        if (y[x] != s[s.size() - 1])
        {
            cout << "ID Wrong" << endl;
        }
        else
        {
            cout << "ID Corrent" << endl;
        }
    }
    system("pause");
    return 0;
}