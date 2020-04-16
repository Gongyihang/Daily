#include <iostream>
using namespace std;
//公众号：一航代码
int main()
{
    int num;
    cin >> num;
    if (num > 0) {
        cout << "1" << endl;
    } else if (num == 0) {
        cout << "0" << endl;
    } else if (num < 0) {
        cout << "-1" << endl;
    }
    system("pause");
    return 0;
}
