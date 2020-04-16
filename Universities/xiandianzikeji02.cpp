#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    string a, b;
    cin >> a >> b;
    int maxlen = 0, index = 0;
    vector<vector<int>> c(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= (int)a.size(); i++) {
        for (int j = 1; j <= (int)b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            if (c[i][j] >= maxlen) {
                maxlen = c[i][j];
                index = i - maxlen;
            }
        }
    }
    cout << maxlen << endl
         << a.substr(index, maxlen) << endl;
    system("pause");
    return 0;
}