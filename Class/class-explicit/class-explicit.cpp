/*************************************************************************
**文件: Class\class-explicit\class-explicit.cpp
**作者: shyfan
**日期: 2024/10/15 11:19:44
**功能: explicit
*************************************************************************/

class Test1
{
public:
    Test1(int a)
    {
        m_a = a;
    }

private:
    int m_a;
};

class Test2
{
public:
    explicit Test2(int a)
    {
        m_a = a;
    }

private:
    int m_a;
};

int main()
{
    Test1 t1 = 1; // 隐式转换
    Test1 t11(1); // 显示转换

    // Test2 t2 = 2; // 显示转换 错误 不能隐式转换
    Test2 t2(2); // 显示转换

    return 0;
}
