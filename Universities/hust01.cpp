#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <math.h>
using namespace std;
int main()
{
    vector<string> words;                   //存单词，vector长度即单词个数
    vector<int> count(130, 0);              //英文字母的最大ASCII值不超过122，记住小写a为97，再加26-1得z为122
    string word;
    while ((cin >> word))                   //使用while和cin组合循环读入字符串以回车结束在后面加一个getchar
    {
        char c = getchar();
        for (int i = 0; i < word.size(); i++)
        {
            count[tolower(word[i])]++;      //将字符全部转换为小写，并以ascii值为下标，数组值为出现次数计数
        }
        words.push_back(word);
        if (c == '\n')                      //判断回车
        {
            break;
        }
    }
    vector<char> res;                       //出现次数最多的字符数组
    int max_num_of_ch = 0;                  //最大出现次数
    int num_of_ch = 0;
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] != 0)                  //字符出现
        {
            num_of_ch += count[i];
            if (count[i] > max_num_of_ch)   //当前字符出现次数最多
            {
                vector<char>().swap(res);   //清空字符数组
                res.push_back(i);           //将当前字符push进数组
                max_num_of_ch = count[i];
            }
            else if (count[i] == max_num_of_ch)//如果多个字符出现次数相等，push进数组
            {
                res.push_back(i);
            }
        }
    }

    cout << num_of_ch << endl;
    cout << words.size() << endl;
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ' ';                  //输出多个字符，以空格隔开。循环到size-1
    }
    cout << res[res.size() - 1] << endl;        //最后一个字符连接回车输出
    cout << max_num_of_ch << endl;
    system("pause");
    return 0;
}