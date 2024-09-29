# array-multi

多维数组

```cpp
#include <iostream>

int main()
{
    int arrA[5] = {1, 2, 3, 4, 5};
    int arrB[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    std::cout << "arrA = " << arrA << std::endl;         // 输出数组的地址
    std::cout << "&arrA[0] = " << &arrA[0] << std::endl; // 输出数组的第一个元素的地址
    std::cout << "&arrA[1] = " << &arrA[1] << std::endl; // 输出数组的第二个元素的地址
    std::cout << "arrA + 1 = " << arrA + 1 << std::endl; // 输出数组的第二个元素的地址

    std::cout << "arrB = " << arrB << std::endl;               // 输出数组的地址
    std::cout << "&arrB[0][0] = " << &arrB[0][0] << std::endl; // 输出数组的第一个元素的地址
    std::cout << "&arrB[0][1] = " << &arrB[0][1] << std::endl; // 输出数组的第二个元素的地址
    std::cout << "arrB + 1 = " << arrB + 1 << std::endl;       // 输出数组的第二行的地址

    std::cout << "&arrB[2][2] = " << &arrB[2][2] << std::endl;         // 输出数组的第三行第三个元素的地址
    std::cout << "*(arrB + 2) + 3 = " << *(arrB + 2) + 2 << std::endl; // 输出数组的第三行第三个元素的地址
    std::cout << "(arrB + 2) + 3 = " << (arrB + 2) + 2 << std::endl;   // 输出数组的第五行的地址
    std::cout << " & arrB[4][0] = " << &arrB[4][0] << std::endl;       // 输出数组的第五行第一个元素的地址

    return 0;
}
```

结果：

```
arrA = 009FFB2C
&arrA[0] = 009FFB2C
&arrA[1] = 009FFB30
arrA + 1 = 009FFB30
arrB = 009FFAC8
&arrB[0][0] = 009FFAC8
&arrB[0][1] = 009FFACC
arrB + 1 = 009FFADC
&arrB[2][2] = 009FFAF8
*(arrB + 2) + 3 = 009FFAF8
(arrB + 2) + 3 = 009FFB18
 & arrB[4][0] = 009FFB18
```
