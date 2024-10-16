/*************************************************************************
**文件: Class\class-sequential\class-sequential.cpp
**作者: shyfan
**日期: 2024/10/16 16:21:18
**功能: 顺序调用
*************************************************************************/

#include <iostream>

class TestA
{
private:
    int n1;
    int n2;
    int n3;

public:
    TestA() : n2(0), n1(n2 + 2), n3(n2 + 2)
    {
    }

    void print()
    {
        std::cout << "n1 = " << n1 << std::endl;
        std::cout << "n2 = " << n2 << std::endl;
        std::cout << "n3 = " << n3 << std::endl;
    }
};

int main()
{
    TestA a;
    a.print();

    return 0;
}
