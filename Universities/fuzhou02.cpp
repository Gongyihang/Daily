#include <bits/stdc++.h>
#define MAX_SIZE 10000
using namespace std;

int spiral[MAX_SIZE][MAX_SIZE];

void print_spiral(int x, int y, int num, int n)
{
    if (n <= 0)
    {
        return;
    }
    if (n == 1)
    {
        spiral[x][y] = num;
        return;
    }
    for (int i = x; i < x + n - 1; i++)     //向右遍历
    {
        spiral[y][i] = num++;
    }
    for (int i = y; i < y + n - 1; i++)     //向下遍历
    {
        spiral[i][y + n - 1] = num++;
    }
    for (int i = x + n - 1; i > x; i--)     //向左遍历
    {
        spiral[y + n - 1][i] = num++;
    }
    for (int i = y + n - 1; i > y; i--)     //向上遍历
    {
        spiral[i][x] = num++;
    }

    print_spiral(x + 1, y + 1, num, n - 2);
}

int main()
{
    fill(spiral[0], spiral[0] + MAX_SIZE * MAX_SIZE, -1);
    int n;
    cin >> n;
    print_spiral(0, 0, 1, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", spiral[i][j]);
        }
        cout << endl;
    }

    system("pause");
    return 0;
}