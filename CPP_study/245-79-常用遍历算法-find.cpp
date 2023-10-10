
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

				学习目标：

					掌握常用的查找算法

				算法简介：

					find          //查找元素
					find_if       //按条件查找元素
					adjacent_find //查找相邻重复元素
					binary_search //二分查找法
					count         //统计元素个数
					count_if      //按条件统计元素个数

				5.2.1 find

					功能描述：

						查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

					函数原型：

						find(iterator beg, iterator end, value);
							// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
							// beg   开始迭代器
							// end   结束迭代器
							// value 查找的元素

					总结： 利用find可以在容器中找指定的元素，返回值是迭代器
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

	// 重载符号==，让find知道如何对比；使用const防止数据被修改
	bool operator==(const Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

// 查找内置数据类型
void test01()
{
	vector<int> v;
	
	// 添加数据到容器
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找 5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	
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

// 查找自定义数据类型
void test02()
{
	vector<Person> v;

	// 创建数据
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	// 添加到容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// 需要查找的数据
	Person ppp("b", 20);

	// 查找 是否有数据和ppp相同的
	vector<Person>::iterator it = find(v.begin(), v.end(), ppp);

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
	// 查找内置数据类型
	test01();

	// 查找自定义数据类型
	test02();

	return 0;
}