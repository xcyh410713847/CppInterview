/*************************************************************************
**文件: Static\static-scope\static-scope.cpp
**作者: shyfan
**日期: 2024/10/02 10:36:44
**功能: 作用域
*************************************************************************/

#include <iostream>

#include "static-scope1.h"
#include "static-scope2.h"

int main()
{
    std::cout << "g_static_scope1 = " << g_static_scope1 << std::endl;
    std::cout << "g_static_scope2 = " << g_static_scope2 << std::endl;

    return 0;
}
