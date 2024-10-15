/*************************************************************************
**文件: Class\class-virtual\class-virtual.cpp
**作者: shyfan
**日期: 2024/10/15 17:13:03
**功能: 虚函数
*************************************************************************/

#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base::Base()" << std::endl;
    }

    virtual void print1()
    {
        std::cout << "Base::print1()" << std::endl;
    }

    virtual void print2()
    {
        std::cout << "Base::print2()" << std::endl;
    }
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        std::cout << "Derived1::Derived1()" << std::endl;
    }

    virtual void print1() override
    {
        std::cout << "Derived1::print1()" << std::endl;
    }

    virtual void print2() override
    {
        std::cout << "Derived1::print2()" << std::endl;
    }

    void print3()
    {
        std::cout << "Derived1::print3()" << std::endl;
    }
};

class Derived2 : public Base
{
public:
    Derived2()
    {
        std::cout << "Derived2::Derived2()" << std::endl;
    }

    virtual void print2() override
    {
        std::cout << "Derived2::print2()" << std::endl;
    }
};

class Derived3 : public Base
{
public:
    Derived3()
    {
        std::cout << "Derived3::Derived3()" << std::endl;
    }

    void print3()
    {
        std::cout << "Derived3::print3()" << std::endl;
    }
};

int main()
{
    Base *pBase = new Base();
    pBase->print1(); // Base::print1()
    pBase->print2(); // Base::print2()

    Derived1 *pBaseDerived1 = (Derived1 *)pBase;
    pBaseDerived1->print1(); // Base::print1()
    pBaseDerived1->print2(); // Base::print2()
    pBaseDerived1->print3(); // Derived1::print3()

    Derived3 *pBaseDerived3 = (Derived3 *)pBase;
    pBaseDerived3->print3(); // Derived1::print3()

    Derived1 *pDerived1 = new Derived1();
    pDerived1->print1(); // Derived1::print1()
    pDerived1->print2(); // Derived1::print2()

    Base *pDerived1Base = pDerived1;
    pDerived1Base->print1(); // Derived1::print1()
    pDerived1Base->print2(); // Derived1::print2()

    Derived2 *pDerived2 = new Derived2();
    pDerived2->print1(); // Base::print1()
    pDerived2->print2(); // Derived2::print2()

    Derived3 *pDerived3 = new Derived3();
    pDerived3->print1(); // Base::print1()
    pDerived3->print2(); // Base::print2()

    return 0;
}
