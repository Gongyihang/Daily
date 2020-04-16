#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
//公众号：一航代码
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int t, move;
        cin >> t >> move;
        vector<int>::iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            if (*it == t) {
                break;
            }
        }
        v.erase(it); //vector的erase真正把这个元素从容器中删除,后面的元素会前移。end表示当前容器末尾
        v.insert(it + move, t);
    }

    for (int i = 0; i < (int)v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << endl;
    system("pause");
    return 0;
}