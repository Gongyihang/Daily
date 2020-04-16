#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
string encode(string s)
{
    for (int i = 0; i < (int)s.size(); i++) {
        if (isupper(s[i])) {
            s[i] = (s[i] - 'A' + 3 + 26) % 26 + 'A';
        } else {
            s[i] = (s[i] - 'a' + 3 + 26) % 26 + 'a';
        }
    }
    return s;
}

string decode(string s)
{
    for (int i = 0; i < (int)s.size(); i++) {
        if (isupper(s[i])) {
            s[i] = (s[i] - 'A' - 3 + 26) % 26 + 'A';
        } else {
            s[i] = (s[i] - 'a' - 3 + 26) % 26 + 'a';
        }
    }
    return s;
}

int main()
{
    string s;
    bool flag = 0;
    cin >> s >> flag;
    if (!flag) {
        string en = encode(s);
        cout << en << endl;
    } else {
        string de = decode(s);
        cout << de << endl;
    }
    system("pause");
    return 0;
}