/*************************************************************************
**文件: Array\array-empty\array-empty.cpp
**作者: shyfan
**日期: 2024/09/27 17:52:27
**功能: 空数组
*************************************************************************/

#include <iostream>

struct A
{
    int a[];
};

int main()
{
    // 使用空数组来实现可变长结构体
    A *p = (A *)malloc(sizeof(A) + sizeof(int) * 2); // 为两个整数分配额外的空间
    p->a[0] = 1;
    p->a[1] = 2;

    std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
    std::cout << "p->a[0] = " << p->a[0] << std::endl;
    std::cout << "p->a[1] = " << p->a[1] << std::endl;

    return 0;
}
