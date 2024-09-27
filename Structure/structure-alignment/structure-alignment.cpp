/*************************************************************************
**文件: Structure\structure-alignment\structure-alignment.cpp
**作者: shyfan
**日期: 2024/09/27 15:24:41
**功能: 结构体对齐
*************************************************************************/

#include <iostream>
#include <string>

#pragma region 普通结构体

struct A
{
    char a; // 1 byte   // 3 bytes padding
    int b;  // 4 bytes
    char c; // 1 byte   // 3 bytes padding
};

struct A_Optimize
{
    char a; // 1 byte
    char c; // 1 byte   // 2 bytes padding
    int b;  // 4 bytes
};

struct B
{
    char a;        // 1 byte   // 3 bytes padding
    std::string b; // 28 bytes
    int c;         // 4 bytes
};

struct C
{
    char a;  // 1 byte   // 3 bytes padding
    int b;   // 4 bytes
    short c; // 2 bytes // 2 bytes padding
};

struct C_Optimize
{
    char a;  // 1 byte
    short c; // 2 bytes // 1 byte padding
    int b;   // 4 bytes
};

#pragma endregion 普通结构体

#pragma region 使用标准对齐方式

struct alignas(8) D_8 // 最低使用 4
{
    char a; // 1 byte   // 3 bytes padding
    int b;  // 4 bytes
    char c; // 1 byte   // 7 bytes padding
};

struct alignas(8) D_8_Optimize // 最低使用 4
{
    char a; // 1 byte
    char c; // 1 byte   // 2 bytes padding
    int b;  // 4 bytes  // 4 byte padding
};

struct alignas(2) D_2 // 最低使用 2
{
    char a;  // 1 byte  // 1 byte padding
    short b; // 2 bytes
    char c;  // 1 byte // 1 byte padding
};

struct alignas(2) D_2_Optimize // 最低使用 2
{
    char a;  // 1 byte  // 1 byte padding
    char c;  // 1 byte // 1 byte padding
    short b; // 2 bytes
};

#pragma endregion 使用标准对齐方式

#pragma region 使用 #pragma pack(n) 指定对齐方式

#pragma pack(push, 1)

struct E
{
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
};
#pragma pack(pop)

#pragma endregion 使用 #pragma pack(n) 指定对齐方式

#pragma region 结构体中的空数组

struct F
{
    char a;  // 1 byte  // 3 bytes padding
    int b[]; // 0 byte
};

struct G
{
    int a[0]; // 0 byte
    char b; // 1 byte   // 3 bytes padding
};

struct H
{
    int b[0]; // 0 byte
};

struct I
{
};


#pragma endregion 结构体中的空数组

int main()
{
    std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
    std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(void*) = " << sizeof(void *) << std::endl;
    std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
    std::cout << "sizeof(double) = " << sizeof(double) << std::endl;
    std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;
    std::cout << "sizeof(std::string) = " << sizeof(std::string) << std::endl;

    std::cout << std::endl;

    std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
    std::cout << "sizeof(A_Optimize) = " << sizeof(A_Optimize) << std::endl;
    std::cout << "sizeof(B) = " << sizeof(B) << std::endl;
    std::cout << "sizeof(C) = " << sizeof(C) << std::endl;
    std::cout << "sizeof(C_Optimize) = " << sizeof(C_Optimize) << std::endl;

    std::cout << "sizeof(D_8) = " << sizeof(D_8) << std::endl;
    std::cout << "sizeof(D_8_Optimize) = " << sizeof(D_8_Optimize) << std::endl;
    std::cout << "sizeof(D_2) = " << sizeof(D_2) << std::endl;
    std::cout << "sizeof(D_2_Optimize) = " << sizeof(D_2_Optimize) << std::endl;

    std::cout << "sizeof(E) = " << sizeof(E) << std::endl;

    std::cout << "sizeof(F) = " << sizeof(F) << std::endl;
    std::cout << "sizeof(G) = " << sizeof(G) << std::endl;
    std::cout << "sizeof(H) = " << sizeof(H) << std::endl;
    std::cout << "sizeof(I) = " << sizeof(I) << std::endl;

    return 0;
}
