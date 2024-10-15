/*************************************************************************
**文件: Class\class-friend\class-friend.cpp
**作者: shyfan
**日期: 2024/10/15 11:46:48
**功能: 友元类和友元函数
*************************************************************************/

#include <iostream>

class C
{
    friend class B; // B是C的友元类

public:
    C(int c) : m_c(c) {}

private:
    int m_c;
};

class B
{
    friend class A; // A是B的友元类
public:
    B() {};
    B(int b) : m_b(b) {}
    void print(C c)
    {
        std::cout << "B::m_b = " << m_b << std::endl;
        std::cout << "C::m_c = " << c.m_c << std::endl;
    }

private:
    int m_b;
};

class A
{
public:
    A(int a) : m_a(a) {}
    void print(B b, C c)
    {
        std::cout << "A::m_a = " << m_a << std::endl;
        std::cout << "B::m_b = " << b.m_b << std::endl;
        // std::cout << "C::m_c = " << c.m_c << std::endl; // 友元关系不具有传递性
    }

private:
    int m_a;
};

class B1 : public B
{
public:
    B1(int b1) : m_b1(b1) {}
    void print(C c)
    {
        std::cout << "B::m_b = " << m_b1 << std::endl;
        // std::cout << "C::m_c = " << c.m_c << std::endl; // 友元关系不具有继承性
    }

private:
    int m_b1;
};

int main()
{
    A a(1);
    B b(2);
    C c(3);
    B1 b1(4);

    a.print(b, c);

    b.print(c);

    b1.print(c);

    return 0;
}
