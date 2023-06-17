
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

				3.7.1 list基本概念

				3.7.2 list构造函数

				3.7.3 list 赋值和交换

				3.7.4 list 大小操作

				3.7.5 list 插入和删除

				3.7.6 list 数据存取

				3.7.7 list 反转和排序

				3.7.8 排序案例

					案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高

					排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

					总结：

						对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序

						高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
*/

#include <iostream>
#include <list>

using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

public:
	string m_Name;  //姓名
	int m_Age;      //年龄
	int m_Height;   //身高
};

void printList(const list<Person>& l)
{
	for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << (*it).m_Name << " "
			<< (*it).m_Age << " "
			<< (*it).m_Height << " "
			<< endl;
	}
	cout << endl;
}


// 指定排序规则
bool ComparePerson(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return  p1.m_Age < p2.m_Age;
	}
}

void test01()
{
	list<Person> l;

	Person p1("张三", 20, 100);
	Person p2("李四", 30, 200);
	Person p3("王五", 30, 300);
	Person p4("赵六", 50, 400);
	Person p5("孙七", 60, 500);

	l.push_back(p2);
	l.push_back(p1);
	l.push_back(p3);
	l.push_back(p5);
	l.push_back(p4);

	printList(l);

	// 排序
	// 自定义类型排序 需要指定规则，需要回调函数 或是 仿函数
	cout << "排序后" << endl;

	l.sort(ComparePerson);

	printList(l);

}

int main()
{
	test01();

	return 0;
}