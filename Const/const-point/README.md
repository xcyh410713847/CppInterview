# const-point

代码如下：

```cpp
int main()
{
    int a = 10;
    int b = 20;
    const int *p = &a; // 指向的值不能改变
    p = &b;            // 指向的地址可以改变
    //*p = 30; //指向的值不能改变

    int *const q = &a; // 指向的地址不能改变
    *q = 30;           // 指向的值可以改变
    // q = &b; //指向的地址不能改变

    const int *const r = &a; // 指向的值和地址都不能改变
    // r = &b; //指向的地址不能改变
    //*r = 30; //指向的值不能改变

    return 0;
}
```

结果：

```

```
