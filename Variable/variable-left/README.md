# variable-left

具名且不可被移动

代码如下：

```cpp
int main()
{
    std::cout << "&(Hello, World!) " << &("Hello, World!") << std::endl;

    return 0;
}
```

结果如下：

```
&(Hello, World!) 00764012
```
