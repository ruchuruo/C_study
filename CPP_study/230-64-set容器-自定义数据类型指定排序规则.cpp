
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

		3 STL- 常用容器

			3.1 string容器

			3.2 vector容器

			3.3 deque容器

			3.4 案例-评委打分

			3.5 stack容器

			3.6 queue 容器

			3.7 list容器

			3.8 set/ multiset 容器

				3.8.1 set基本概念

				3.8.2 set构造和赋值

				3.8.3 set大小和交换

				3.8.4 set插入和删除

				3.8.5 set查找和统计

				3.8.6 set和multiset区别

				3.8.7 pair对组创建

				3.8.8 set容器排序

					学习目标：

						set容器默认排序规则为从小到大，掌握如何改变排序规则

					主要技术点：

						利用仿函数，可以改变排序规则

					总结：

						对于自定义数据类型，set必须指定排序规则才可以插入数据
*/

#include <iostream>
#include <set>

using namespace std;

class MyCompar
{
public:
	// 重载()
	// const成员函数
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}

	/*
		来自弹幕：
			唯一的例外是对于mutable修饰的成员。加了const的成员函数可以被非const对象和const对象调用，
			非静态成员函数后面加const（加到非成员函数或静态成员后面会产生编译错误），
			表示成员函数隐含传入的this指针为const指针，决定了在该成员函数中，
			任意修改它所在的类的成员的操作都是不允许的（因为隐含了对this指针的const引用）；
			但不加const的成员函数只能被非const对象调用。
	*/
};



class Person
{
public:
	Person(string name, int age) :m_Name(name), m_Age(age)
	{

	}

	string m_Name;
	int m_Age;
};

class MyComparPerson
{
public:
	// 重载()
	// const成员函数
	bool operator()(const Person& p1, const Person& p2) const
	{
		// 按照年龄降序
		return p1.m_Age > p2.m_Age;
	}
};





// set存放内置数据类型
void test01()
{
	set<int> s;

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << endl;



	// 指定排序规则 从大到小，插数据前指定才有用
	set<int, MyCompar> s2;

	// 来自弹幕：不用匿名函数是因为set<int,MyCompare>中的两个形参都是数据类型，MyCompare是一种class类型。用函数的话，不是数据类型，底层应该会报错。

	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);

	for (set<int, MyCompar>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << endl;
}

// set存放自定义数据类型
void test02()
{
	// 对于自定义数据类型需要指定排序规则
	set<Person, MyComparPerson> s;

	// 创建Person对象
	Person p1("张三", 20);
	Person p2("李四", 30);
	Person p3("王五", 40);
	Person p4("赵六", 50);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, MyComparPerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << it->m_Name << " " << it->m_Age << endl;
	}
	cout << endl;
}

int main()
{
	// set存放内置数据类型
	test01();

	// set存放自定义数据类型
	test02();

	return 0;
}