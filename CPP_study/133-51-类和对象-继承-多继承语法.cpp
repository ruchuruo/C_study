
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

				4.6.7 多继承语法

					C++允许一个类继承多个类

					语法： class 子类 ：继承方式 父类1 ， 继承方式 父类2...

					多继承可能会引发父类中有同名成员出现，需要加作用域区分

					C++实际开发中不建议用多继承

					总结： 多继承中如果父类中出现了同名情况，子类使用时候要加作用域
*/

#include <iostream>

using namespace std;

class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base2 {
public:
	Base2()
	{
		m_A = 200;  //开始是m_B 不会出问题，但是改为mA就会出现不明确
	}
public:
	int m_A;
};

//语法：class 子类：继承方式 父类1 ，继承方式 父类2 
class Son : public Base2, public Base1
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
public:
	int m_C;
	int m_D;
};


//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test01()
{
	Son s;
	cout << "sizeof Son = " << sizeof(s) << endl;// 16
	cout << s.Base1::m_A << endl;
	cout << s.Base2::m_A << endl;
}

int main()
{
	test01();

	return 0;
}

/*
	来自弹幕：那不就是吕布了吗
	来自弹幕：神他么吕布语法
*/