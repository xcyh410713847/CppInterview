/*************************************************************************
**文件: Const\const-class\const-class.cpp
**作者: shyfan
**日期: 2024/10/08 11:41:40
**功能: const成员变量和const成员函数
*************************************************************************/

#include <iostream>

class Test
{
    const int a;
    int b;

public:
    // const成员变量只能在初始化列表中初始化
    // Test()
    // {
    //     a = 10;
    //     b = 20;
    // }

    Test() : a(10), b(20) {} // 初始化列表

    Test(int x, int y) : a(x), b(y) {}

    void print() const
    {
        std::cout << "a = " << a << ", b = " << b << std::endl;
    }
};

int main()
{
    Test t;
    t.print();

    Test t1(100, 200);
    t1.print();

    return 0;
}
