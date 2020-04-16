#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    int num = 0;
    while (cin >> num) {
        string s;
        string t;
        while (num != 0) {

            t = to_string(num % 2);
            s += t;
            num /= 2;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
        if (char ch = getchar() == '\n') {
            break;
        }
    }
    return 0;
}