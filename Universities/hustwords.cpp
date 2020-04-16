#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <math.h>
using namespace std;


// void split1(const string& s, vector<string>& tokens, const string& delimiters = " ")
// {
//         string::size_type lastPos = s.find_first_not_of(delimiters, 0);
//         string::size_type pos = s.find_first_of(delimiters, lastPos);
//         while (string::npos != pos || string::npos != lastPos) {
//                 // transform(s.begin(),s.end(),s.begin(),::tolower);//toupper和tolower在C++中定义分别在std和cctype中
//                 // transform(s.begin(),s.end(),s.begin(),(int (*)(int))tolower);//https://blog.csdn.net/qq_31186409/article/details/50545682
//                 string t = s.substr(lastPos, pos - lastPos);
//                 transform(t.begin(), t.end(), t.begin(), ::tolower); //toupper和tolower在C++中定义分别在std和cctype中
//                 for (int i = 0; i < t.size(); i++)
//                 {
//                     count[tolower(t[i])]++;
//                 }
//                 tokens.push_back(t);
//                 lastPos = s.find_first_not_of(delimiters, pos);
//                 pos = s.find_first_of(delimiters, lastPos);
//         }
// }
int main()
{
    vector<string> words;
    vector<int> count(130, 0);
    string word;
    char c;
    bool flag = true;
    while ((cin >> word).get(c) && flag)
    {
        if (c == '\n')
        {
            flag = false;
        }
        for (int i = 0; i < word.size(); i++)
        {
            count[tolower(word[i])]++;
        }
        words.push_back(word);
        if (!flag)
        {
            break;
        }
    }
    // string s;
    // getline(cin, s);
    // char *word = strtok(s.data(), " ");
    // while (word != NULL)
    // {
    //     for (int i = 0; i < sizeof(*word); i++)
    //     {
    //         count[tolower(word[i])]++;
    //     }
    //     words.push_back(word);
    //     word = strtok(NULL, " ");
    // }
    // split1(s,words," ");
    vector<char> res;
    int max_num_of_ch = 0;
    int num_of_ch = 0;
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] != 0)
        {
            num_of_ch += count[i];
            if (count[i] > max_num_of_ch)
            {
                vector<char>().swap(res);
                res.push_back(i);
                max_num_of_ch = count[i];
            }
            else if (count[i] == max_num_of_ch)
            {
                res.push_back(i);
            }
        }
    }

    cout << num_of_ch << endl;
    cout << words.size() << endl;
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] << ' ';
    }
    cout << res[res.size() - 1] << endl;
    cout << max_num_of_ch << endl;
    system("pause");
    return 0;
}