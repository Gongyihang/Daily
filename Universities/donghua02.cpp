#include <iostream>
#include <vector>
using namespace std;
//@公众号：一航代码
int main()
{
    vector<int> v;
    int t;
    cin >> t;
    v.push_back(t);                     //先将一个数字push进数组
    while (cin >> t)
    {
        if (v[v.size() - 1] != t)       //若当前数字和前一个元素不相等，将其push进数组​
        {
            v.push_back(t);
        }
        if (char ch = getchar() == '\n')
        {
            break;
        }
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << endl;
    system("pause");
    return 0;
}