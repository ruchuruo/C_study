
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

				1.3.4 类模板对象做函数参数

				1.3.5 类模板与继承

				1.3.6 类模板成员函数类外实现

				1.3.7 类模板分文件编写

				1.3.8 类模板与友元

					学习目标：

						掌握类模板配合友元函数的类内和类外实现

					全局函数类内实现 - 直接在类内声明友元即可

					全局函数类外实现 - 需要提前让编译器知道全局函数的存在

					总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别
*/

#include <iostream>

using namespace std;

//2、全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template<class T1, class T2> class Person;

//如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 

template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}



template<class T1, class T2>
class Person
{
	//1、全局函数配合友元   类内实现
	friend void printPerson(Person<T1, T2>& p)
	{
		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	}


	//全局函数配合友元  类外实现
	/*
		这是一个普通函数的声明
			friend void printPerson2(Person<T1, T2>& p); 

		这是一个函数模板的实现
			template<class T1, class T2>
			void printPerson2(Person<T1, T2>& p){}

		所以导致这两个不是一套东西
		所以要加上 空模板参数列表<>，告诉编译器这是一个 函数模板的函数声明
			friend void printPerson2<>(Person<T1, T2>& p);

		全局函数类外实现 - 需要提前让编译器知道全局函数的存在
		(实现在上方)
	*/
	friend void printPerson2<>(Person<T1, T2>& p);

public:

	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}


private:
	T1 m_Name;
	T2 m_Age;

};



//1、全局函数在类内实现
void test01()
{
	Person <string, int >p("Tom", 20);
	printPerson(p);
}

//2、全局函数在类外实现
void test02()
{
	Person <string, int >p("Jerry", 30);
	printPerson2(p);
}

int main()
{
	test01();

	test02();

	return 0;
}

/*
	来自弹幕：你让我想起了左脚踩右脚，右脚踩左脚上天
*/