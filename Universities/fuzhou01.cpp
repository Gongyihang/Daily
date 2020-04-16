#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "Please enter the length of the array:" << endl;
    int n = 0;
    cin >> n;
    cout << "Please enter the element of the array:" << endl;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Please enter the region of the array you want to sum:" << endl;
    int p = 0, q = 0;
    cin >> p >> q;
    int sum = 0;
    for (int i = p; i <= q; i++)
    {
        sum += arr[i];
    }
    cout << "The sum of the array in the region is: " << endl
         << sum << endl;
    system("pause");
    return 0;
}
