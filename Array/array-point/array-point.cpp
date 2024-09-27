/*************************************************************************
**文件: Array\array-point\array-point.cpp
**作者: shyfan
**日期: 2024/09/27 18:15:46
**功能: 数组指针
*************************************************************************/

#include <iostream>

int main()
{
    int arr_size = 3;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = i;
    }

    std::cout << "arr = " << arr << std::endl;         // 输出数组的地址
    std::cout << "&arr = " << &arr << std::endl;       // 输出数组的地址
    std::cout << "&arr[0] = " << &arr[0] << std::endl; // 输出数组的第一个元素的地址

    // 进行加1
    std::cout << "$arr[1] = " << &arr[1] << std::endl;                       // 输出数组的第二个元素的地址
    std::cout << "$arr[arr_size - 1] = " << &arr[arr_size - 1] << std::endl; // 输出数组的最后一个元素的地址
    std::cout << "arr + 1 = " << arr + 1 << std::endl;                       // 输出数组的第二个元素的地址
    std::cout << "&arr + 1 = " << &arr + 1 << std::endl;                     // 输出数组的后面的地址
    std::cout << "&arr[0] + 1 = " << &arr[0] + 1 << std::endl;               // 输出数组的第二个元素的地址

    return 0;
}
