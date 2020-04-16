#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    string s;
    cin >> s;
    bool flag = false;
    if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_') {
        for (int i = 1; i < (int)s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '_') || (s[i] >= '0' && s[i] <= '9')) {
                flag = true;
            }
        }
    }

    if (flag) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    system("pause");
    return 0;
}