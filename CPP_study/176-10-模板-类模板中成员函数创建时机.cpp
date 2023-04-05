
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程
		
		本阶段主要针对C++ 泛型编程 和 STL 技术做详细讲解，探讨C++更深层的使用

		1 模板

			1.1 模板的概念

			1.2 函数模板

			1.3 类模板

				1.3.1 类模板语法

				1.3.2 类模板与函数模板区别

				1.3.3 类模板中成员函数创建时机

					类模板中成员函数和普通类中成员函数创建时机是有区别的：

						普通类中的成员函数一开始就可以创建
						类模板中的成员函数在调用时才创建

					总结：类模板中的成员函数并不是一开始就创建的，在调用时才去创建
*/

#include <iostream>

using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;

	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
	// 不确定是哪种数据类型，所以不会创建

	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }
};

void test01()
{
	MyClass<Person1> m;

	m.fun1();

	// Person1 类中没有 showPerson2() 函数
	//m.fun2();//编译会出错，说明函数调用才会去创建成员函数
}

int main()
{
	test01();

	return 0;
}