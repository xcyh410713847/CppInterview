# static-initialization

## 如果未赋值

代码如下：

```cpp
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
```

结果：

```
a = 0
b = 
c = 00000000
d = 0
arr[0] = 0
arr[1] = 0
arr[2] = 0
```

## 初始化时机

### 在C语言中

静态局部变量和全局变量一样，数据都存放在全局区域，所以在主程序之前，编译器已经为其分配好了内存，在编译阶段分配好了内存之后就进行初始化，在程序运行结束时变量所处的全局内存会被回收。所以在c语言中无法使用变量对静态局部变量进行初始化。

### C++与C的区别

c++主要引入了类这种东西，要进行初始化必须考虑到相应的构造函数和析构函数，而且很多时候构造或者析构函数中会指定我们定义的操作，并非简单的分配内存。因此为了造成不必要的影响（一些我不需要的东西被提前构造出来）所以c++规定**全局或者静态对象**在**首次**用到的时候才会**初始化**。

#### 静态初始化(static initialization)

静态初始化分为zero initialization和const initialization，主要在程序加载时完成初始化

zero initialization 存储在 bss段

const initialization 存储在data段

#### 动态初始化(dynamic initialization)

需要调用函数完成初始化，如int a = foo()，全局和类静态成员变量在main()函数执行前初始化，局部静态变量则在函数执行时初始化

## 线程安全

C语言中非局部静态变量一般在main执行之前的静态初始化过程中分配内存并初始化，可以认为是线程安全的；

C++11标准针规定了局部静态变量初始化是线程安全的。这里的线程安全指的是：一个线程在初始化 m 的时候，其他线程执行到 m 的初始化这一行的时候，就会挂起而不是跳过。
