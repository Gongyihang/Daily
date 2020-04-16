#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//函数的声明
void sum(int a, int b);

int main()
{
    sum(1,2);
    // extern int i;       //仅声明一个变量i
    // cout << i << endl; //提示错误
    // int i;             //声明并定义i,但不提倡
    // cout << i << endl; //会输出0，并提示警告，变量未初始化

    /*未初始化的变量含有一个不确定的值
    使用未初始化变量的值是一种严重错误的变成行为并且很难调试
    尽管大多数编译器都能对一部分使用未初始化变量的行为提出警告
    但严格来说，编译器并未要求检查此类错误
    所以，请养成良好习惯，声明定义变量必初始化！
    */
    // int i = 0; //声明并定义i，并初始化为0，提倡
    // cout << i << endl;

    system("pause");
    return 0;
}

//函数的定义
void sum(int a, int b){
};