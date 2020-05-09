# 第二章 面试需要的基础知识

## 不同面试官对应聘者的期待
1. C++的基础知识，如面向对象的特性，构造函数、析构函数、动态绑定，能够反映出应聘者是否善于把握问题本质，有没有耐心深入一个问题。另外还有常用的设计模式、UML图等反映应聘者是否有软件工程方面的经验。

2. C++中对内存的使用管理。

3. 字符串处理这一类的问题、并发控制、算法、复杂度。

## 知识点

**1. 在C++中，有哪四个与类型转换相关的关键字？这些关键字各有什么特点，应该在什么场合下使用？**

[C++中，有哪4种与类型转换相关的关键字？各有什么特点？应该在什么场合下使用？](https://www.cnblogs.com/mjiang2017/p/9358032.html)

    答：C++中，四个与类型转换相关的关键字：static_cast、const_cast、reinterpret_cast、dynamic_cast。
    
    static_cast特点：静态转换，在编译处理期间。 
    应用场合：主要用于C++中内置的基本数据类型之间的转换，但是没有运行时类型的检测来保证转换的安全性。
    ①用于基类和子类之间的指针或引用之间的转换，这种转换把子类的指针或引用转换为基类表示是安全的；
    进行下行转换，把积累的指针或引用转换为子类表示时，由于没有进行动态类型检测，所以是不安全的。
    ②把void类型的指针转换成目标类型的指针（不安全）。
    ③不能用于两个不相关的类型转换。
    ④不能把const对象转换成非const对象。

**2. 定义一个空的类型，里面没有任何成员变量和成员函数。对该类型求sizeof，得到的结果是多少？**

[定义一个空类型，里面没有任何成员变量和成员函数。对该类型求sizeof 结果？](https://blog.csdn.net/zhuiqiuzhuoyue583/article/details/92846054)

    答：结果为1。

**为什么不是0？**

    空类型实例中不包含任何信息，但是当我们声明该类型的实例的时候，它必须在内存中占有一定的空间，否则无法使用这些实例。
    至于占多少空间，由编译器决定。Visual Studio中每个空类型的实例占用1字节的空间。

**如果在该类型中添加一个构造函数和析构函数，再对该类型求sizeof，得到的结果又是多少？**

    还是1.调用构造函数和析构函数只需要知道函数的地址即可，而这些函数的地址只与类型相关，而与类型的实例无关，编译器也不会因为这两个函数而在实例中添加任何额外的信息。

**如果析构函数标记为虚函数呢？**

    C++编译器一旦发现一个类型中有虚函数，就会为该类型生成虚函数表，并在该类型的每一个实例中添加一个指向虚函数表的指针。
    在32位机器上，一个指针占4个字节的空间，因而sizeof得到4；如果是64位的机器，一个指针占8字节的空间，结果为8。
![miaoshu](https://img-blog.csdnimg.cn/20190619210057207.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3podWlxaXV6aHVveXVlNTgz,size_16,color_FFFFFF,t_70)
**代码示例：**
```c++
#include <iostream>
using namespace std;
class X{};
class Y : public virtual X
{};
class Z : public virtual X
{};
class A : public Y, public Z
{};
int main(){
    int x = 0;
    x = sizeof(X);              //在32位系统中  在64位系统中
    cout << "x：" << x << endl; //result 1      result 1

    int y = 0;
    y = sizeof(Y);
    cout << "y：" << y << endl; //result 4      result 8

    int z = 0;
    z = sizeof(Z);
    cout << "z：" << z << endl; //result 4      result 8

    int a = 0;
    a = sizeof(A);
    cout << "a：" << a << endl; //result 8      result 16

    system("pause");
    return 0;
}
```
    C++标准规定类的大小不为0，空类的大小为1，当类不包含虚函数和非静态数据成员时，其对象大小也为1。
    因为在声明该类的实例的时候，必须在内存中占有一定的空间，否则无法使用这些实例。

    对有虚函数的类来说，必须为它的对象提供运行时类型信息(RTTI，Run-Time Type Information)和关于虚函数表的信息，
    常见的做法是在对象中放置一个指向虚函数表的指针。
    此外，为了支持RTTI，许多编译器都把该类型信息放在虚函数表中。
    但是，是否必须采用这种实现方法，C++标准没有规定，主流编译器均采用的一种方案。

**对象大小**  =  **虚函数指针**  +   **所有非静态数据成员大小**   +   **因对齐而多占的字节**

```c++
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
    cout << sizeof(b) << endl; //result=1                                       1
    cout << sizeof(c) << endl; //result=8，本来使用6个字节就可以，但是需要补齐    16
    cout << sizeof(d) << endl; //result=8，                                     16

    system("pause");
    return 0;
}
```

**3.关于c++中不允许复制构造函数传值参数的理解**

[关于c++中不允许复制构造函数传值参数的理解](https://blog.csdn.net/xiaoquantouer/article/details/70145348)

[C++拷贝构造函数（复制构造函数）详解](http://c.biancheng.net/view/151.html)


