
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

			2.1 STL的诞生

			2.2 STL基本概念

			2.3 STL六大组件

			2.4 STL中容器、算法、迭代器

			2.5 容器算法迭代器初识

				2.5.1 vector存放内置数据类型

				2.5.2 Vector存放自定义数据类型

					学习目标：vector中存放自定义数据类型，并打印输出
*/

#include <iostream>
#include <vector>   // 容器 vector 的头文件

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

public:
	string m_Name;
	int m_Age;
};



// 存放自定义数据类型
void test01()
{
	vector<Person> v;

	Person p1("张三", 10);
	Person p2("李四", 20);
	Person p3("王五", 30);
	Person p4("赵六", 40);
	Person p5("孙七", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// 遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout
			<< "名字 " << (*it).m_Name << " "
			<< "年龄 " << it->m_Age
			<< 
		endl;

		/*
			it 是指针，解引用后是<>里的内容 Person
		*/
	}

	cout << endl;
}



// 存放自定义数据类型 的 指针
void test02()
{
	vector<Person*> v;

	Person p1("张三", 10);
	Person p2("李四", 20);
	Person p3("王五", 30);
	Person p4("赵六", 40);
	Person p5("孙七", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// 遍历
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout
			<< "名字 " << (*(*it)).m_Name << " "
			<< "年龄 " << (*it)->m_Age
			<<
		endl;

		/*
			it 是指针，解引用后是<>里的内容 Person*
		*/
	}
}



int main()
{
	// 存放自定义数据类型
	test01();

	// 存放自定义数据类型 的 指针
	test02();

	return 0;
}