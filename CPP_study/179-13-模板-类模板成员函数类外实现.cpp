
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

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

					学习目标：能够掌握类模板中的成员函数类外实现

					总结：类模板中成员函数类外实现时，需要加上模板参数列表
*/

#include <iostream>

using namespace std;

//类模板中成员函数类外实现
template<class T1, class T2>
class Person
{
public:
	//成员函数类内声明
	Person(T1 name, T2 age);
	void showPerson();

public:
	T1 m_Name;
	T2 m_Age;
};

//构造函数 类外实现
template<class T1, class T2>// 这里 template 的 T1 T2 是 Person(T1 name, T2 age) 函数中的 T1 T2
Person<T1, T2>::Person(T1 name, T2 age)// 这里 Person<T1, T2> 的 T1 T2 是告诉编译器是类模板中成员函数类外实现，没有 <T1, T2> 就是普通类中成员函数类外实现
{
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数 类外实现
template<class T1, class T2>// 虽然成员函数中没有用到 T1 T2，但是这个是类模板中成员函数
void Person<T1, T2>::showPerson()
{
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}

void test01()
{
	Person<string, int> p("Tom", 20);
	p.showPerson();
}

int main()
{
	test01();

	return 0;
}