#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*
1_.统计各个元音字母出现的次数并输出
Input：huihuikaoyanzhuninchenggong
Output:
       Number of vowel a: 2
       Number of vowel e: 1
       Number of vowel i: 3
       Number of vowel o: 2
       Number of vowel u: 3

程序逻辑：
①从输入内容中读取所有字符
②令每个字符都与元音字母的集合进行比较
③如果字符与某个元音字母匹配，将该字母的数量加1
④输出统计结果
*/

/*
基本结构：
switch(ch):
    case 'a':
        acnt++;
        break;
    case 'e':
        ecnt++;
        break;
    case 'i':
        icnt++;
        break;
    case 'o':
        ocnt++;
        break;
    case 'u':
        ucnt++;
        break;
*/


int main()
{
    char ch;

    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    //一直读入字符，直到遇到回车符号
    while ((ch = getchar()) != '\n')
    {
        // break;
        // continue;//如果这里加continue或者break，则程序陷入死循环
        switch (ch) //对ch进行匹配
        {
        case 'a':
            ++aCnt;
            break; //返回进行下一次while,下同
            // continue; //返回进行下一次while,下同，这里加break或continue作用相同
        case 'e':
            ++eCnt;
            break;
            // continue;
        case 'i':
            ++iCnt;
            break;
            // continue;
        case 'o':
            ++oCnt;
            break;
            // continue;
        case 'u':
            ++uCnt;
            break;
            // continue;
        }
    }
    //输出元音字母的个数
    cout << "Number of vowel a: " << aCnt << '\n';
    cout << "Number of vowel e: " << eCnt << '\n';
    cout << "Number of vowel i: " << iCnt << '\n';
    cout << "Number of vowel o: " << oCnt << '\n';
    cout << "Number of vowel u: " << uCnt << endl;
    system("pause");
    return 0;
}