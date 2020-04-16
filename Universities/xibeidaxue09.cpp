#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    string s;
    map<string, int> m;
    char ch;
    while (cin >> s) {
        for (int i = 0; i < (int)s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        m[s]++;
        if ((ch = getchar()) == '\n') {
            break;
        }
    }

    cout << (int)m.size() << endl;
    system("pause");
    return 0;
}