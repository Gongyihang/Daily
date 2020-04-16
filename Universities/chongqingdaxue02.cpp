#include <iostream>
#include <string>
using namespace std;
//此题记住小写字母的ASCII值比大写字母的大
//大小写字母ASCII值相差32
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
            // s[i] = tolower(s[i]);
        }
    }
    cout << s << endl;
    system("pause");
    return 0;
}