#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

struct student
{
    string name;        //学生姓名
    vector<int> scores; //学生成绩数组，默认数组最后一个数值保存总成绩
    bool flag = true;   //若该同学未挂科，则flag为true，否则为false
};

bool cmp(student a, student b) //总成绩除以总科目数，默认数组中最后一个数值为总成绩，按平均成绩从高到低排序
{
    return a.scores[a.scores.size() - 1] / a.scores.size() - 1 > b.scores[b.scores.size() - 1] / b.scores.size() - 1;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<student> s;
        for (int i = 0; i < n; i++)
        {
            student t;
            cin >> t.name;
            int score;
            while (cin >> score) //循环读入成绩
            {
                t.scores.push_back(score);
                if (score < 60) //如该同学挂科，将其flag置为false
                {
                    t.flag = false;
                }
                char ch;
                if ((ch = getchar()) == '\n') //回车保留在输入流中，如遇回车则结束循环
                {
                    break;
                }
            }
            s.push_back(t);
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (!s[i].flag) //flag为false，该同学挂科，将该同学按格式输出
            {
                cout << "*[" << s[i].name << "]";
                for (int j = 0; j < s[j].scores.size() - 1; j++)
                {
                    cout << " " << s[i].scores[j];
                }
                cout << endl;
            }
        }

        sort(s.begin(), s.end(), cmp); //结构体排序，按照平均成绩从高到低

        for (int i = 0; i < s.size(); i++) //按格式输出
        {
            cout << s[i].name;
            for (int j = 0; j < s[i].scores.size(); j++)
            {
                cout << " " << s[i].scores[j];
            }
            cout << endl;
        }
    }

    system("pause");
    return 0;
}