
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

		1 内存分区模型

		2 引用

		3 函数提高

		4 类和对象

			4.1 封装

			4.2 对象的初始化和清理

			4.3 C++对象模型和this指针

			4.4 友元

			4.5 运算符重载

			4.6 继承

				4.6.1 继承的基本语法

				4.6.2 继承方式

				4.6.3 继承中的对象模型

				4.6.4 继承中构造和析构顺序

				4.6.5 继承同名成员处理方式

				4.6.6 继承同名静态成员处理方式

					问题：继承中同名的静态成员在子类对象上如何进行访问？

					静态成员和非静态成员出现同名，处理方式一致

						访问子类同名成员 直接访问即可
						访问父类同名成员 需要加作用域

                    总结：同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）
*/

#include <iostream>

using namespace std;

class Base
{
public:
    static void func()
    {
        cout << "Base - static void func()" << endl;
    }
    static void func(int a)
    {
        cout << "Base - static void func(int a)" << endl;
    }

    static int m_A;
};

int Base::m_A = 100;

class Son : public Base
{
public:
    static void func()
    {
        cout << "Son - static void func()" << endl;
    }
    static int m_A;
};

int Son::m_A = 200;

//同名成员属性
void test01()
{
    //通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    cout << "Son  下 m_A = " << s.m_A << endl;
    cout << "Base 下 m_A = " << s.Base::m_A << endl;

    //通过类名访问
    cout << "通过类名访问： " << endl;
    cout << "Son  下 m_A = " << Son::m_A << endl;
    cout << "Base 下 m_A = " << Son::Base::m_A << endl;

    // 第一个 :: 代表通过类名方式访问，第二个 :: 代表访问父类作用域下
}

//同名成员函数
void test02()
{
    //通过对象访问
    cout << "通过对象访问： " << endl;
    Son s;
    s.func();
    s.Base::func();

    cout << "通过类名访问： " << endl;
    Son::func();
    Son::Base::func();

    //出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
    Son::Base::func(100);
}

int main()
{
    //同名成员属性
    test01();

    //同名成员函数
    test02();

    return 0;
}