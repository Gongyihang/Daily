#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int sum = 0;
    vector<int> array(10, 0);
    vector<int> res;
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
        if (array[i] % 2 != 0) {
            res.push_back(array[i]);
            sum += array[i];
        }
    }
    for (int i = 0; i < (int)res.size() - 1; i++) {
        cout << res[i] << " ";
    }
    cout << res[res.size() - 1] << endl
         << res.size() << endl
         << sum << endl;
    system("pause");
    return 0;
}