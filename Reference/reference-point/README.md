# reference-point

引用与指针的区别

相同点：

指针和引用在内存中都占用4个或者8个字节的存储空间，都必须在定义的时候给初始化；

不同点：

引用不能为空，但是指针可以；

指针允许寻址，引用不可以。&p返回指针常量本身的地址，而&b是被引用对象的地址；

数组元素可以是指针，但是不能是引用；

在C++中，指针和引用经常用于函数的参数传递，然而，指针传递参数和引用传递参数是有本质上的不同的：**指针传递**参数本质上是**值传递**的方式，它所传递的是一个地址值。值传递的特点是被调函数对形式参数的任何操作都是作为局部变量进行，不会影响主调函数的实参变量的值。而在**引用传递**过程中， 被调函数的形参虽然也作为局部变量在栈中开辟了内存空间，但是这时存放的是由主调函数放进来的实参变量的地址（指针放的是实参变量地址的副本）；

`sizeof引用` 得到的是所指向的变量(对象)的大小，而 `sizeof指针` 得到的是指针本身的大小；

代码如下：

```cpp


#include <iostream>

int main()
{
    int a = 10;

    int &b = a; // b是a的引用
    int* const p = &a; // p是a的常量指针

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "*p = " << *p << std::endl;

    b = 20; // b是a的引用，所以这里相当于给a赋值

    std::cout << "a = " << a << std::endl;
    std::cout << "*p = " << *p << std::endl;

    *p = 30; // p是a的常量指针，所以这里相当于给a赋值

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    // 打印地址
    std::cout << "&a = " << &a << std::endl;    // a的地址
    std::cout << "&b = " << &b << std::endl;    // b是a的引用，所以这里是a的地址，引用无法获取自己的地址
    std::cout << "p = " << p << std::endl;      // p是常量指针，所以这里是a的地址
    std::cout << "&p = " << &p << std::endl;    // p是常量指针，所以这里是p的地址

    // 打印大小
    struct STest
    {
        int a;
        char b;
    } sTest;

    STest &rTest = sTest;
    STest *pTest = &sTest;

    std::cout << "sizeof(sTest) = " << sizeof(sTest) << std::endl; // 8 = 4 + 1 + 3
    std::cout << "sizeof(rTest) = " << sizeof(rTest) << std::endl; // 8 是sTest的引用，所以大小和sTest一样
    std::cout << "sizeof(pTest) = " << sizeof(pTest) << std::endl; // 4 是指针的大小

    return 0;
}

```

结果：

```
a = 10
b = 10
*p = 10
a = 20
*p = 20
a = 30
b = 30
&a = 00EEF804
&b = 00EEF804
p = 00EEF804
&p = 00EEF7FC
sizeof(sTest) = 8
sizeof(rTest) = 8
sizeof(pTest) = 4
```
