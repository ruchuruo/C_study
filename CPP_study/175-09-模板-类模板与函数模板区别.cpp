
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

					类模板与函数模板区别主要有两点：

						类模板没有自动类型推导的使用方式
						类模板在模板参数列表中可以有默认参数

					总结：

						类模板使用只能用显示指定类型方式
						类模板中的模板参数列表可以有默认参数
*/

#include <iostream>

using namespace std;

//类模板
template<class NameType, class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

//1、类模板没有自动类型推导的使用方式
void test01()
{
	// Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导
	Person <string, int>p("孙悟空", 1000); //必须使用显示指定类型的方式，使用类模板
	p.showPerson();
}

//2、类模板在模板参数列表中可以有默认参数
void test02()
{
	Person <string> p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数
	p.showPerson();
}

// 没指定类型就用默认类型
void test3()
{
	Person <string, string>p("张三", "abcd");
	p.showPerson();
}

int main()
{
	test01();

	test02();

	test3();

	return 0;
}