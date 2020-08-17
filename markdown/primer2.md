1. 构造函数最好用初值列，初试列来赋初值。
complex (double r = 0, double i = 0): re(r), im(i){}
2. 构造函数可以有多个-发生重载（重载常常发生在构造函数身上）
3. 构造函数使用默认参数的时候，不能使用构造函数重载。（二义性，编译器不知道调用哪一个了）
4. 函数重载，在编译器看来，其实名称是不一样的。


任何成员函数重载函数都有一个this的pointer，谁调用重载函数，就指向谁  
头文件中，须用防卫式声明  
复数中的+=重载
函数需要return by reference


local的东西，不能return by reference

非成员函数重载没有this  
复数+复数  
复数+double  
double+复数  
创建临时对象typename(),可以看做调用了构造函数  
返回的时候不能return by reference  

定义一个类需要考虑什么事情？
1. 构造函数初值列  
2. 函数该不该加const  
3. 传值尽量考虑pass by reference，要不要加const  
4. 函数return要不要加reference  
5. 数据尽量放在private里面  
6. 函数主要放在public里面  


在类的内部声明的函数为成员函数，friend友元函数支持访问本类的数据  



带指针的类：（Big Three 三个特殊函数：拷贝构造函数、拷贝赋值函数、析构函数）  
构造函数和析构函数  
拷贝构造函数：  
为什么叫拷贝呢？因为它接收的类型就是这个类它自己的类型 
```cpp 
String::String(const String& str){}
```
拷贝赋值函数：  
为什么叫赋值呢？是对操作符=的重载  
```cpp
String& String::operator=(const String& str){
    if(this == &str){//拷贝赋值一定要考虑是不是自我赋值
        return *this;//必须做这个检查，譬如有一个对象，有另一个指针同时指向这个对象
    }

    //三步操作：
    delete[] m_data;//自杀
    m_data = new char[strlen(str.m_data) + 1];//分配空间
    strcpy(m_data,str.m_data);//拷贝
    return *this;
}
```
对<<的重载函数一定要是全局函数，而不是成员函数，否则 << 就不是对cout操作了。  


#### 栈、堆  
栈：存在于某作用域的一块内存空间。当调用函数，函数本身即会形成一个stack用来放置他所接受的参数，以及返回地址  
堆：是指由操作系统提供的一块global内存空间，程序可动态分配，从中获得若干区域。  
static修饰的变量其生命周期在作用域结束之后仍然存在，直到整个程序结束。  
全局变量的作用域也是整个程序  
```cpp
Complex* p = new Complex;
delete p;
```
内存对齐，是16的倍数，保证最后一位是0，给出去了最后一位变为1，没有使用则为0。  


array的new要搭配array的delete  
```cpp
String* p = new String[3];
delete[] p;//调用3次析构函数
delete p;//调用1次析构函数，造成“指针指向的地方”内存泄漏
```  


