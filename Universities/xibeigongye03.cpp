#include <algorithm>
#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int k = 0; k < n; k++) {
        string s;
        stack<char> st1;
        stack<char> st2;
        bool flag = true;       //记录此时栈是否为空，栈空则不能进行pop操作
        cin >> s;               //flag为false则仅有右括号，无法匹配
        for (int i = 0; i < (int)s.size(); i++) {
            switch (s[i]) {
            case '(': {
                st1.push('(');
                break;
            }
            case ')': {
                if (st1.empty()) {
                    flag = false;
                    break;
                } else {
                    st1.pop();
                    break;
                }
            }
            case '[': {
                st2.push('[');
                break;
            }
            case ']': {
                if (st2.empty()) {
                    flag = false;
                    break;
                } else {
                    st2.pop();
                    break;
                }
            }
            }
        }
        if (st1.empty() && st2.empty() && flag) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}