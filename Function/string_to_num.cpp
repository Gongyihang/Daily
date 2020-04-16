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
    string s = "123";
    int num;
    stringstream ss;
    ss << s;
    ss >> num;
    system("pause");
    return 0;
}