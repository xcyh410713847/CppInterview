/*************************************************************************
**文件: Class\class-inheritance\class-inheritance.cpp
**作者: shyfan
**日期: 2024/10/16 18:19:18
**功能: 类的继承
*************************************************************************/

#include <iostream>

class Base
{
private:
    int m_n1;

public:
    Base(int n1) : m_n1(n1)
    {
        std::cout << "Base::Base()" << std::endl;
    }
};

class Derived1 : public Base
{
};

int main()
{
    // Derived1 d1(10); // 错误，没有合适的构造函数

    return 0;
}
