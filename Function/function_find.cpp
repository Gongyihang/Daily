#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(123);
    auto it = find(v.begin(), v.end(), 123);
    if (it != v.end())
    {
        cout << "exist" << endl;
    }
    else
    {
        cout << "Not exist" << endl;
    }

    set<int> s;
    s.insert(10);
    if (s.find(10) != s.end())
    {
        cout << "exist" << endl;
    }
    else
    {
        cout << "Not exist" << endl;
    }

    map<int, int> m;
    m.insert(pair<int, int>(1, 1));
    auto tit = m.find(1);
    if (tit != m.end())
    {
        cout << tit->first << " " << tit->second << endl;
    }
    else
    {
        cout << "Not exist" << endl;
    }


    auto pos = m.find(1);
    int flag = (pos == m.end()) ? 0 : 1;
    //flag = 0,表示map中没有要查找的key值
    //flag = 1，表示map中存在查找的key值，且迭代器指向该key值

    //判断某key是否存在也可以使用map的count方法来间接判定
    //count接受一个参数key值，返回map中key值为给定值的元素总数
    map<int,string> m2;
    int mount = m2.count(100);
    //如果mount=0，则map中不存在key值为100的元素，反之则存在


    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string>(1, "student_one"));
    mapStudent.insert(pair<int, string>(2, "student_two"));
    mapStudent.insert(pair<int, string>(3, "student_three"));
    map<int, string>::iterator iter;
    iter = mapStudent.find(1);
    if (iter != mapStudent.end())
    {
        cout << "Find, the value is" << iter->second << endl;
    }
    else
    {
        cout << "Do not Find" << endl;
    }

    system("pause");
    return 0;
}