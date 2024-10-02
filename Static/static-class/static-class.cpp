﻿/*************************************************************************
**文件: Static\static-class\static-class.cpp
**作者: shyfan
**日期: 2024/10/02 10:54:02
**功能: 类的静态成员
*************************************************************************/

#include <iostream>

class Test
{
public:
    static int static_member1;
    static int static_member2;

public:
    static void func()
    {
        std::cout << "static func" << std::endl;
    }

    static const void func1()
    {
        std::cout << "static const func" << std::endl;
    }

    // 错误，静态成员函数不能加const修饰
    // static void func2() const
    // {
    //     std::cout << "static func2" << std::endl;
    // }
};

int Test::static_member1 = 1; // 静态成员变量必须在类外初始化，不然无法编译通过
int Test::static_member2 = 2; // 静态成员变量必须在类外初始化，不然无法编译通过

int main()
{
    Test::func();
    Test::func1();

    std::cout << "Test::static_member1 = " << Test::static_member1 << std::endl;
    std::cout << "Test::static_member2 = " << Test::static_member2 << std::endl;

    Test t1;
    t1.func();
    std::cout << "t.static_member1 = " << t1.static_member1 << std::endl;

    Test t2;
    t2.func();
    std::cout << "t2.static_member2 = " << t2.static_member2 << std::endl;

    return 0;
}
