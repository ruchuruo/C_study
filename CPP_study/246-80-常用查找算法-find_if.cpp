
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

		3 STL- 常用容器

		4 STL- 函数对象

		5 STL- 常用算法

			5.1 常用遍历算法

			5.2 常用查找算法

				5.2.1 find

				5.2.2 find_if

					功能描述：

						按条件查找元素

					函数原型：

						find_if(iterator beg, iterator end, _Pred);
							// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
							// beg   开始迭代器
							// end   结束迭代器
							// _Pred 函数或者谓词（返回bool类型的仿函数）

					总结：
						find_if按条件查找使查找更加灵活，提供的仿函数可以改变不同的策略

						来自弹幕：
							find 是具体查找, find_if 是条件查找.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 自定义数据类型
class Person
{
public:
	Person(string name, int age) :m_Name(name), m_Age(age) {}

	string m_Name;
	int m_Age;
};

// 谓词1
class Greater5
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

// 谓词2
class Greater20
{
public:
	bool operator()(Person& val)
	{
		return val.m_Age > 20;
	}
};

// 内置数据类型
void test01()
{
	vector<int> v;

	// 插入数据
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找大于5的数
	vector<int>::iterator it =
		find_if(v.begin(), v.end(), Greater5());

	// 判断是否找到
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << *it << endl;
	}
}

// 自定义数据类型
void test02()
{
	vector<Person> v;

	// 创建数据
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	// 插入数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// 找年龄大于20的人
	vector<Person>::iterator it =
		find_if(v.begin(), v.end(), Greater20());

	// 判断是否找到
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << (*it).m_Name << " " << (*it).m_Age << endl;
	}
}

int main()
{
	// 内置数据类型
	test01();

	// 自定义数据类型
	test02();

	return 0;
}