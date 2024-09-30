/*************************************************************************
**文件: static&const\static-initialization\static-initialization.cpp
**作者: shyfan
**日期: 2024/09/30 16:34:52
**功能: 静态初始化
*************************************************************************/

#include <iostream>
#include <string>

static int a;         // 静态初始化为 0
static std::string b; // 静态初始化为空字符串
static int *c;        // 静态初始化为 nullptr
static float d;       // 静态初始化为 0.0
static int arr[3];    // 静态初始化为 0

int main()
{
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "arr[1] = " << arr[1] << std::endl;
    std::cout << "arr[2] = " << arr[2] << std::endl;

    return 0;
}
