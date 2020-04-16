#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& v, int low, int high)
{
    if (low < high) {
        int i = low, j = high, pivot = v[low];
        while (i < j) {
            while (i < j && v[j] >= pivot) { //while中须判断i<j
                --j;
            }
            if (i < j) { //此处if不可缺少
                v[i++] = v[j];
            }
            while (i < j && v[i] <= pivot) { //while中须判断i<j
                ++i;
            }
            if (i < j) { //此处if不可缺少
                v[j--] = v[i];
            }
        }
        v[i] = pivot;
        quicksort(v, low, i - 1);
        quicksort(v, i + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    quicksort(v, 0, n - 1);

    cout << v[0];
    for (int i = 1; i < n; i++) {
        cout << " " << v[i];
    }
    return 0;
}
