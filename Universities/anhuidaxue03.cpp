#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> v, res;
    string s;
    int length = 0;
    while (cin >> s) {
        v.push_back(s);
        if ((int)s.size() > length) {
            length = s.size();
            res.clear();
            res.push_back(s);
        }else if((int)s.size() == length){
            res.push_back(s);
        }
        char ch;
        if((ch = getchar()) == '\n'){
            break;
        }
    }
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " " << v[i].size() << endl;
    }
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}