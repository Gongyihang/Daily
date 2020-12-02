#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*
统计元音字母的个数
Input：huihuikaoyanzhuninchenggong
Output: 
       Number of vowel : 11
*/

int main()
{
    char ch;
    int vowelCnt = 0;

    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++vowelCnt;
            break;
        }
    }
    cout << "Number of vowel : " << vowelCnt << '\n';
    system("pause");
    return 0;
}