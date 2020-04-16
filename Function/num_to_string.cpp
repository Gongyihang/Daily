#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

#include <sstream>

int main()
{
    string s;
    int num = 123;
    stringstream ss;
    ss << num;
    ss >> s;
    cout << s;
    system("pause");
    return 0;
}