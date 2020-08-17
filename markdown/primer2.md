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
