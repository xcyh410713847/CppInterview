/*************************************************************************
**文件: Reference\reference-point\reference-point.cpp
**作者: shyfan
**日期: 2024/10/11 10:43:58
**功能: 引用与指针的区别
*************************************************************************/

#include <iostream>

int main()
{
    int a = 10;

    int &b = a;        // b是a的引用
    int *const p = &a; // p是a的常量指针

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
    std::cout << "&a = " << &a << std::endl; // a的地址
    std::cout << "&b = " << &b << std::endl; // b是a的引用，所以这里是a的地址，引用无法获取自己的地址
    std::cout << "p = " << p << std::endl;   // p是常量指针，所以这里是a的地址
    std::cout << "&p = " << &p << std::endl; // p是常量指针，所以这里是p的地址

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
