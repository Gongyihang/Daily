#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
//http://39.105.108.26/problem.php?cid=1013&pid=1
int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j < n - i + 1; j++) {
            printf(" ");
        }
        for (int k = i; k > 0; k--) {
            printf("* ");
        }
        cout << endl;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        cout << endl;
    }
    return 0;
}