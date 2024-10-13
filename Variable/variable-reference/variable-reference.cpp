/*************************************************************************
**文件: Variable\variable-reference\variable-reference.cpp
**作者: shyfan
**日期: 2024/10/13 11:41:42
**功能: 引用
*************************************************************************/

#include <iostream>
#include <string>

int main()
{
    // 左值引用
    std::string str = "Hello, World!";
    std::string &strRef = str;

    // 常量左值引用
    const int &a = 1;
    // int &b = 1;      // 错误，不能将右值绑定到非常量左值引用

    // 右值引用
    // std::string &&strRRef = str;    // 错误，不能将左值绑定到右值引用
    int &&rrb = 1; // 正确，可以将右值绑定到右值引用
    int i = 1;
    const int &rc = i * 2; // 正确，可以将右值绑定到常量左值引用
    // int &rc = i * 2; // 错误，i * 2 是一个右值，不能将右值绑定到非常量左值引用
    int &&rrc = i * 2; // 正确，可以将右值绑定到右值引用

    /*
        右值引用虽然是引用右值，但是其本身是左值
        右值引用是一个左值，因此不能将右值引用绑定到右值引用
    */
    int &&rrd = 1;
    std::cout << "&rrd = " << &rrd << std::endl;

    // 通过API判断是否是左值引用和右值引用
    std::cout << "strRef is_lvalue_reference " << std::is_lvalue_reference<decltype(strRef)>::value << std::endl;
    std::cout << "strRef is_rvalue_reference " << std::is_rvalue_reference<decltype(strRef)>::value << std::endl;
    std::cout << "rrb is_rvalue_reference " << std::is_rvalue_reference<decltype(rrb)>::value << std::endl;

    return 0;
}
