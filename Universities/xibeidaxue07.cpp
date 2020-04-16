#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        switch (s[i]) {
        case 'A':
        case 'a': {
            count_a++;
            break;
        }
        case 'E':
        case 'e': {
            count_e++;
            break;
        }
        case 'I':
        case 'i': {
            count_i++;
            break;
        }
        case 'O':
        case 'o': {
            count_o++;
            break;
        }
        case 'U':
        case 'u': {
            count_u++;
            break;
        }
        }
    }
    cout << "a:" << count_a << endl;
    cout << "e:" << count_e << endl;
    cout << "i:" << count_i << endl;
    cout << "o:" << count_o << endl;
    cout << "u:" << count_u << endl;
    system("pause");
    return 0;
}