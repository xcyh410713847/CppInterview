# structure-alignment

## 对齐原理

**对齐**是指数据在内存中的起始地址必须是特定值的倍数。每种数据类型都有其对齐要求，通常是该类型大小的倍数

* **char** 对齐到 1 字节
* **short** 对齐到 2字节
* **int** 对齐到 4 字节
* **double** 对齐到 8 字节

对齐规则有助于 CPU 高效访问内存。许多架构的 CPU 在访问对齐内存地址时速度更快，而对未对齐地址的访问则可能导致性能显著降低，甚至引发硬件异常


## 结构体对齐的影响因素

### **成员对齐**

结构体的每个成员都会根据其类型的对齐要求分别进行对齐。结构体中的第一个成员通常与结构体的起始地址对齐，但后续成员的排列可能会导致填充字节（padding）的出现

### **结构体对齐**

整个结构体的对齐要求通常取决于其最宽对齐成员的大小。这意味着结构体对象在内存中的地址通常会是最大小的成员的对齐要求的倍数

### **填充字节**

为了满足对齐要求，编译器可能在结构体成员之间或结构体末尾插入填充字节。这会导致内存使用效率下降

## 对齐优化

### 重新排列成员

代码如下：

```cpp
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
```

结果：

```
sizeof(A) = 12
sizeof(A_Optimize) = 8
```

### #pragma pack

用于控制结构体数据对齐的编译指令，设定结构体成员的对齐方式为 `n` 字节

代码如下：

```cpp
#pragma pack(push, 1)

struct E
{
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
};
#pragma pack(pop)
```

结果：

```
sizeof(E) = 6
```

### **使用标准对齐属性**

在 C++11 中，可以使用 `alignas` 关键字指定对齐要求，帮助优化特定的数据结构

代码如下：

```cpp
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
    char a; // 1 byte  // 1 byte padding
    short b;  // 2 bytes
    char c; // 1 byte // 1 byte padding
};

struct alignas(2) D_2_Optimize // 最低使用 2
{
    char a;  // 1 byte  // 1 byte padding
    char c;  // 1 byte // 1 byte padding
    short b; // 2 bytes
};
```

结果：

```
sizeof(D_8) = 16
sizeof(D_8_Optimize) = 8
sizeof(D_2) = 6
sizeof(D_2_Optimize) = 4
```

**注意：alignas中的值不能小于结构体中最小的基础类型字节数**
