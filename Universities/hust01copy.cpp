#include <iostream>
#include <algorithm>
using namespace std;

int hashtable[26] = {0};                            //统计各个小写字母出现次数
int cnt_alpha = 0, cnt_word = 0, MAX = -1;
int main()
{
    string str;
    while (cin >> str)
    {
        cnt_alpha += str.size();                    //统计字母个数
        cnt_word++;                                 //统计英文单词个数
        for (int i = 0; i < str.size(); ++i)
        {                                           //转小写字母，统计各个小写字母出现次数
            str[i] = tolower(str[i]);
            hashtable[str[i] - 'a']++;
            MAX = max(MAX, hashtable[str[i] - 'a']); //记录字母最大出现次数
        }
        char ch = getchar();                        //结束死循环，新技能get
        if (ch == '\n')
        {
            break;
        }
    }
    printf("%d\n", cnt_alpha);                      //输出字母的个数
    printf("%d\n", cnt_word);                       //输出英文单词的个数
    int flag = 0;
    for (int i = 0; i < 26; ++i)
    {                                               //输出出现次数最多的小写字母
        if (hashtable[i] == MAX)
        {
            if (flag == 0)
            {
                printf("%c", i + 'a');
                flag = 1;
            }
            else
                printf(" %c", i + 'a');
        }
    }
    printf("\n%d", MAX);                            //输出最大出现次数
    return 0;
}