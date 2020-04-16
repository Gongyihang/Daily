#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    int d;
    cin >> s >> d;
    string res;
    int qu, re = 0; //qu为商、re为余数
    bool flag = false; //商是否出现非0位，是为true,商一直为0，则一直为false，一直continue
    for (int i = 0; i < (int)s.size(); i++) {
        re = re * 10 + s[i] - '0';//核心
        qu = re / d;
        re = re % d;             
        if ((qu == 0) && !flag) {
            continue;
        }
        res += to_string(qu);
        flag = true;
    }
    if (!flag) { //商为0的情况
        cout << "0 " << re;
    } else {
        cout << res << " " << re << endl;
    }
    system("pause");
    return 0;
}