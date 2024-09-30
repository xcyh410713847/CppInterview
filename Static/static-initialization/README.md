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
