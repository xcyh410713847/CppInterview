# variable-reference

在C++11之前，引用分为左值引用和常量左值引用两种，但是自C++11起，引入了右值引用，也就是说，在C++11中，包含如下3中引用：

* 左值引用
* 常量左值引用(不希望被修改)
* 右值引用

在C++11中引入了右值引用，因为右值的生命周期很短，右值引用的引入，使得可以延长右值的生命周期。在C++中规定，右值引用是&&即由2个&表示，而左值引用是一个&表示。右值引用的作用是为了 `绑定右值`

**右值引用虽然是引用右值，但是其本身是左值**

`左值引用和右值引用就属于类型`,而 `左值和右值则属于值类别范畴`

[从4行代码看右值引用](https://www.cnblogs.com/qicosmos/p/4283455.html)

## 右值引用

特点：

1. 通过右值引用的声明，右值又“重获新生”，其生命周期与右值引用类型变量的生命周期一样长，只要该变量还活着，该右值临时量将会一直存活下去
2. 右值引用独立于左值和右值。意思是右值引用类型的变量可能是左值也可能是右值
3. T&& t在发生自动类型推断的时候，它是未定的引用类型（universal references），如果被一个左值初始化，它就是一个左值；如果它被一个右值初始化，它就是一个右值，它是左值还是右值取决于它的初始化。需要注意的是，仅仅是当发生自动类型推导（如函数模板的类型自动推导，或auto关键字）的时候，T&&才是universal references

## 代码

代码如下：

```cpp
#include <iostream>
#include <string>

int main()
{
    // 左值引用
    std::string str = "Hello, World!";
    std::string &strRef = str;
    std::cout << "strRef = " << strRef << std::endl;

    // 常量左值引用
    const int &a = 1;
    std::cout << "a = " << a << std::endl;
    // int &b = 1;      // 错误，不能将右值绑定到非常量左值引用

    // 右值引用
    // std::string &&strRRef = str;    // 错误，不能将左值绑定到右值引用
    int &&rrb = 1; // 正确，可以将右值绑定到右值引用
    std::cout << "rrb = " << rrb << std::endl;
    int i = 1;
    const int &rc = i * 2; // 正确，可以将右值绑定到常量左值引用
    std::cout << "rc = " << rc << std::endl;
    // int &rc = i * 2; // 错误，i * 2 是一个右值，不能将右值绑定到非常量左值引用
    int &&rrc = i * 2; // 正确，可以将右值绑定到右值引用
    std::cout << "rrc = " << rrc << std::endl;

    /*
        右值引用虽然是引用右值，但是其本身是左值
        右值引用是一个左值，因此不能将右值引用绑定到右值引用
    */
    std::cout << "&rrb = " << &rrb << std::endl;

    // 通过API判断是否是左值引用和右值引用
    std::cout << "strRef is_lvalue_reference " << std::is_lvalue_reference<decltype(strRef)>::value << std::endl;
    std::cout << "strRef is_rvalue_reference " << std::is_rvalue_reference<decltype(strRef)>::value << std::endl;
    std::cout << "rrb is_rvalue_reference " << std::is_rvalue_reference<decltype(rrb)>::value << std::endl;

    return 0;
}
```

结果如下：

```
strRef = Hello, World!
a = 1
rrb = 1
rc = 2
rrc = 2
&rrb = 00AFF878
strRef is_lvalue_reference 1
strRef is_rvalue_reference 0
rrb is_rvalue_reference 1
```
