
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

				4.2.1 构造函数和析构函数

				4.2.2 构造函数的分类及调用

				4.2.3 拷贝构造函数调用时机

				4.2.4 构造函数调用规则

				4.2.5 深拷贝与浅拷贝

				4.2.6 初始化列表

					作用：

						C++提供了初始化列表语法，用来初始化属性

						语法：构造函数()：属性1(值1),属性2（值2）... {}

                        来自弹幕：
                            传统赋值初始化是相当于（先声明类，再做赋值操作），
                            初始化列表相当于（直接声明一个有初始值的类型），省略了赋值操作，
                            在大型项目中，class类中成员变量极多的情况下，初始化列表效率更高
*/

#include <iostream>

using namespace std;

class Person
{
public:

    ////传统方式初始化
    //Person(int a, int b, int c)
    //{
    //	m_A = a;
    //	m_B = b;
    //	m_C = c;
    //}

    //初始化列表方式初始化
    //Person() :m_A(10), m_B(20), m_C(30) {}
    Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
    void PrintPerson()
    {
        cout << "mA:" << m_A << endl;
        cout << "mB:" << m_B << endl;
        cout << "mC:" << m_C << endl;
    }

private:
    int m_A;
    int m_B;
    int m_C;
};

int main()
{
    Person p(1, 2, 3);
    p.PrintPerson();

    return 0;
}