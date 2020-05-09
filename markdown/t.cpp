#include <iostream>
using namespace std;

class A
{
};

class B
{
    char ch;
    void func() {}
};

class C
{
    char ch1; //占用1字节
    char ch2; //占用1字节
    virtual void func() {}
};

class D
{
    int in; //占用4字节
    virtual void func() {}
};

int main()
{
    A a;
    B b;
    C c;
    D d;                       //32位系统                                       64位系统
    cout << sizeof(a) << endl; //result=1                                       1
    cout << sizeof(a) << endl; //result=1                                       1
    cout << sizeof(c) << endl; //result=8，本来使用6个字节就可以，但是需要补齐    16
    cout << sizeof(d) << endl; //result=8，                                     16

    system("pause");
    return 0;
}