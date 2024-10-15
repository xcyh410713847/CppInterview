# class-friend

友元的作用是提高了程序的运行效率（即减少了类型检查和安全性检查等都需要时间开销），但它破坏了类的封装性和隐藏性，使得非成员函数可以访问类的私有成员

* 友元关系不能被继承
* 友元关系是单项的，不具有交换性
* 友元关系不具有传递性

## 友元函数

**友元函数**能够使得普通函数直接访问类的保护数据和私有数据成员，避免了类成员函数的频繁调用，可以节约处理器开销，提高程序的效率，但所矛盾的是，即使是最大限度大保护，同样也破坏了类的封装特性，这即是友元的缺点，在现在cpu速度越来越快的今天我们并不推荐使用它。

## 友元类

**友元类**友元类的所有成员函数都是另一个类的友元函数，都可以访问另一个类中的隐藏信息（包括私有成员和保护成员）

## 代码

```cpp
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
```

结果如下：

```
A::m_a = 1
B::m_b = 2
B::m_b = 2
C::m_c = 3
B::m_b = 4
```
