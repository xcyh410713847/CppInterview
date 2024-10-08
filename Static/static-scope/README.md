# static-scope

代码如下：

```cpp
#include <iostream>

#include "static-scope1.h"
#include "static-scope2.h"

class Test1
{
public:
    Test1()
    {
        std::cout << "Test1()" << std::endl;
    }

    ~Test1()
    {
        std::cout << "~Test1()" << std::endl;
    }
};

static Test1 g_test1; // 静态全局变量，只会初始化一次，生命周期和程序一样长

class Test2
{
public:
    Test2()
    {
        std::cout << "Test2()" << std::endl;
    }

    ~Test2()
    {
        std::cout << "~Test2()" << std::endl;
    }
};

void func()
{
    std::cout << "func() Start" << std::endl;
    static Test2 t; // 静态局部变量，只会初始化一次，生命周期和程序一样长
    std::cout << "func() End" << std::endl;
}

int main()
{
    std::cout << "main() Start" << std::endl;

    std::cout << "g_static_scope1 = " << g_static_scope1 << std::endl;
    std::cout << "g_static_scope2 = " << g_static_scope2 << std::endl;

    func();
    func();

    std::cout << "main() End" << std::endl;

    return 0;
}
```

结果：

```
Test1()
main() Start
g_static_scope1 = 1
g_static_scope2 = 2
func() Start
Test2()
func() End
func() Start
func() End
main() End
~Test2()
~Test1()
```
