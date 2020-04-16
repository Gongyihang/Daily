#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    int n;
    cin >> n;
    int sum = 0, flag = 0;
    for (int i = 0; i < n; i++) {
        int state;
        cin >> state;
        if (state == 0) {
            break;
        } else if (state == 1) {
            flag = 0;
            sum += 1;
        } else if (state == 2) {
            flag++;
            sum += 2 * flag;
        }
    }
    cout << sum << endl;
    system("pause");
    return 0;
}