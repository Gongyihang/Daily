#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
string cur;
void strip(string& s)
{
    int pos;
    for (; ~(pos = s.find("//")); s.erase(pos, 1)) //去除//
        ;
    for (; ~(pos = s.find("/./")); s.erase(pos, 2))//去除/./
        ;
    pos = s.find_last_of('/');                     //去除末尾的/
    if (pos > 0)
        if (pos == (int)s.size() - 1) {
            s.erase(pos, 1);
        }
}

void deal_high_level(string& s)
{
    int pos;
    if (s == "") {
        s = cur;
        return;
    }
    if (s[0] != '/') { //不以'/'开头的都是以".."或者'.'开头的，是相对路径
        s = cur + "/" + s;
    }
    for (; ~(pos = s.find("/../"));) {
        if (pos) {
            int rp = s.rfind('/', pos - 1);
            s.erase(rp, pos - rp + 3);
        } else {
            s.erase(pos, 3);
        }
    }
}

int main()
{
    int n;
    cin >> n >> cur;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strip(s);
        deal_high_level(s);
        cout << s << endl;
    }
    system("pause");
    return 0;
}