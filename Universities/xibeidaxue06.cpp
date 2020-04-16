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
    getline(cin,s);
    int count = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'a') {
            count++;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}