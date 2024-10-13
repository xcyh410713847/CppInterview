/*************************************************************************
**文件: Variable\variable-left\variable-left.cpp
**作者: shyfan
**日期: 2024/10/13 11:35:14
**功能: 左值
*************************************************************************/

#include <iostream>

int main()
{
    std::cout << "&(Hello, World!) " << &("Hello, World!") << std::endl;

    return 0;
}
