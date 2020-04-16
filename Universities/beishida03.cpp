#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

struct number {
    int num = 0;
    int count = 0;
};

int main()
{
    int n;
    cin >> n;
    vector<number> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].num;
    }
    int sum = 0;
    for (int j = n - 1; j >= 0; j--) {
        for (int i = j - 1; i >= 0; i--) {
            if (v[i].num > v[j].num) {
                swap(v[i], v[j]);
                v[i].count++;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        sum += v[i].count;
        cout << v[i].count << " ";
    }
    cout << v[n - 1].count << endl;
    cout << sum << endl;
    system("pause");
    return 0;
}