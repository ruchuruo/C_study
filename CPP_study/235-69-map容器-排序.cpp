
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

			3.9 map/ multimap容器

				3.9.1 map基本概念

				3.9.2 map构造和赋值

				3.9.3 map大小和交换

				3.9.4 map插入和删除

				3.9.5 map查找和统计

				3.9.6 map容器排序

					学习目标：

						map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则

					主要技术点:

						利用仿函数，可以改变排序规则

					总结：

						利用仿函数可以指定map容器的排序规则
						对于自定义数据类型，map必须要指定排序规则,同set容器
*/

#include <iostream>
#include <map>

using namespace std;

class MyCompare
{
public:
	// 来自弹幕：vs2019要在成员函数的最后边加一个const变成常函数
	bool operator()(int v1, int v2) const
	{
		// 降序
		return v1 > v2;
	}
};

void printMap(map<int, int, MyCompare>& m)
{
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " = " << (*it).second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int, MyCompare> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	printMap(m);
}

int main()
{
	test01();

	return 0;
}