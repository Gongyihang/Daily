#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    int n, k;
    cin >> n;
    vector<int> v(21, 0);
    for (int i = 0; i < n; i++) {
        cin >> k;
        v[k]++;
    }
    int count = 0;
    for (int i = 0; i < 18; i++) {
        if (v[i] != 0 && v[i + 1] != 0 && v[i + 2] != 0) {
            count++;
            v[i]--;
            v[i + 1]--;
            v[i + 2]--;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}