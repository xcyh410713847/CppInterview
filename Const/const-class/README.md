# const-class

代码如下：

```cpp
class Test
{
    const int a;
    int b;

public:
    // const成员变量只能在初始化列表中初始化
    // Test()
    // {
    //     a = 10;
    //     b = 20;
    // }

    Test() : a(10), b(20) {} // 初始化列表

    Test(int x, int y) : a(x), b(y) {}

    void print() const
    {
        std::cout << "a = " << a << ", b = " << b << std::endl;
    }
};

int main()
{
    Test t;
    t.print();

    Test t1(100, 200);
    t1.print();

    return 0;
}

```

结果：

```
a = 10, b = 20
a = 100, b = 200
```
