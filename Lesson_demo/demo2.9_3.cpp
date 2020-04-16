#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*统计元音字母和非元音字母出现的次数并统计输出
Input：huihuikaoyanzhuninchenggong
Output:
       Number of vowel : 11
       Number of non-vowel : 16
*/

int main()
{
    char ch;
    int vowelCnt = 0, otherCnt = 0;

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
        default://如果ch不是元音字母，就从default标签开始执行并把otherCnt加1
            ++otherCnt;
            break;
        }
    }
    cout << "Number of vowel : " << vowelCnt << '\n';
    cout << "Number of non-vowel : " << otherCnt << endl;
    system("pause");
    return 0;
}