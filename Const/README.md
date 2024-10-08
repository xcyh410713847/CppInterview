﻿# const

## 修饰变量

限定变量为不可修改

## 修饰指针

指针常量和指向常量的指针

## 修饰函数

### const int func(int& i) {}

修饰函数返回值，返回值不可被修改

### int func(const int& i) {}

修饰参数，参数不可被修改

### int func(int& i) const {}

const成员函数，函数内部不能修改类成员变量

## const和类

1. 修饰成员变量，在某个对象的声明周期内是常量，但是对于整个类而言是可以改变的。因为类可以创建多个对象，不同的对象其const成员变量的值是不同的。切记，**不能在类内初始化const成员变量**，因为类的对象没创建前，编译器并不知道const成员变量是什么，因此const数据成员只能在初始化列表中初始化。
2. 修饰成员函数，主要目的是防止成员函数修改成员变量的值，即该成员函数并不能修改成员变量。
3. 修饰对象，常对象，常对象只能调用常函数。
