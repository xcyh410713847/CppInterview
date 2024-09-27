# array-point

## arr和&arr[0]和&arr的不同

首先如果打印的话，三个打印的完全一样，都是数组首元素的地址。&arr应该是整个元素的地址，但是打印出来却是首元素的地址

```cpp
int arr_size = 3;
int arr[arr_size];
for (int i = 0; i < arr_size; i++)
{
    arr[i] = i;
}

std::cout << "arr = " << arr << std::endl;         // 输出数组的地址
std::cout << "&arr = " << &arr << std::endl;       // 输出数组的地址
std::cout << "&arr[0] = " << &arr[0] << std::endl; // 输出数组的第一个元素的地址
```

```
arr = 004EFA24  
&arr = 004EFA24   
&arr[0] = 004EFA24
```

对地址进行加1

```
// 进行加1
std::cout << "$arr[1] = " << &arr[1] << std::endl;                       // 输出数组的第二个元素的地址
std::cout << "$arr[arr_size - 1] = " << &arr[arr_size - 1] << std::endl; // 输出数组的最后一个元素的地址
std::cout << "arr + 1 = " << arr + 1 << std::endl;                       // 输出数组的第二个元素的地址
std::cout << "&arr + 1 = " << &arr + 1 << std::endl;                     // 输出数组的后面的地址
std::cout << "&arr[0] + 1 = " << &arr[0] + 1 << std::endl;               // 输出数组的第二个元素的地址
```

```
$arr[1] = 00B2F860
$arr[arr_size - 1] = 00B2F864
arr + 1 = 00B2F860
&arr + 1 = 00B2F868
&arr[0] + 1 = 00B2F860
```

发现 `&arr` 加1之后与其他两个不一样，这是因为其他两个只移动4个字节取下一个元素的地址了，而 `&arr` 则是移动了12个字节，直接到数组后面的内存地址去了
