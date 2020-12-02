#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;
//值传递
void swap1(int a, int b)
{
    int t = a;
    a = b;
    b = t;
    printf("swap1,a b address: %#x %#x\n", &a, &b);
}

//指针传递
void swap2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    printf("swap2,a b address: %#x %#x\n", a, b);
}
//引用传递
void swap3(int &c, int &d)
{
    int t = c;
    c = d;
    d = t;
    printf("swap3,c d address: %#x %#x\n", &c, &d);
}

int main()
{

    int a = 1, b = 2;
    // swap1(a, b);
    // cout << "swap1:" << a << " " << b << endl;
    // cout << "a b address: " << &a << " " << &b << endl;

    // swap2(&a, &b);
    // cout << "swap2:" << a << " " << b << endl;
    // cout << "a b address: " << &a << " " << &b << endl;

    swap3(a, b);
    cout << "swap3:" << a << " " << b << endl;
    cout << "a b address: " << &a << " " << &b << endl;

    system("pause");
    return 0;
}