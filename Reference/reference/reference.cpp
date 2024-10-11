/*************************************************************************
**文件: Reference\reference\reference.cpp
**作者: shyfan
**日期: 2024/10/11 10:32:13
**功能: 引用
*************************************************************************/

#include <iostream>

int main()
{
    int a = 10;
    int &b = a; // b是a的引用

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    b = 20; // b是a的引用，所以这里相当于给a赋值

    std::cout << "a = " << a << std::endl;

    a = 30;

    std::cout << "b = " << b << std::endl;

    // 引用不能更改指向
    int c = 30;
    int d = 40;
    int &e = c;

    std::cout << "e = " << c << std::endl;

    e = d; // 这里是赋值，不是更改引用指向

    std::cout << "e = " << c << std::endl;

    // 引用不能独立存在，必须初始化
    // int &f;      // 这里会报错
    // int &g = 10; // 这里也会报错

    // 引用不能用于数组，会导致二义性
    // int &h[10]; // 这里会报错，h[0]是h的第一个元素还是h的引用呢？

    return 0;
}
