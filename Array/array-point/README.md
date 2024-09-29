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

`arr` 本身是左值（但不可仅凭此表达式修改），指代数组对象。不过 `arr` 会在大多数场合隐式转换成右值表达式 `&(arr[0])` ，为指针类型，指向 `arr[0]` 。`&arr` 是右值表达式，为指针类型，指向 `arr` 本身。简单来说就是 `arr` 本身不是地址而是指代整个数组，只不过会隐式转成指针罢了

## char a, char* a, char a[], char* a[], char **a 的区别

### char a

定义了一个 `char` 类型的变量 `a`

### char* a 和 char a[]

`char* a` 定义了一个指向 `char` 类型的指针 `a`

`char a[]` 定义了一个 `char` 类型的数组 `a`

对于两个 `a` 来说都能表示数组首地址，但是对于 `char s[]` 和 char* a ，我们可以 `a = s` ,不能 `s = a，不能把指针赋给数组`

### char* a[]

定义了一个存放 `char` 指针类型的数组 `a` ，因为 `*` 优先级低于 `[]`

### char **a

表示一个指向指针的指针

两个 `*` 代表相同的优先级，因此从右往左看，即 `char*(*a)`

`char *a` 就是一个字符串数组，a代表首地址。那么 `char * (*a)` 就是和 `char *a[]` 表达的是一样的意思
