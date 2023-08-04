
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

					学习目标：

						掌握set和multiset的区别

					区别：

						set不可以插入重复数据，而multiset可以
						set插入数据的同时会返回插入结果，表示插入是否成功
						multiset不会检测数据，因此可以插入重复数据

					总结：

						如果不允许插入重复数据可以利用set
						如果需要插入重复数据利用multiset

					pair是将2个数据组合成一组数据，当需要这样的需求时就可以使用pair，
					如stl中的map就是将key和value放在一起来保存。
					另一个应用是，当一个函数需要返回2个数据的时候，可以选择pair。
					pair的实现是一个结构体，主要的两个成员变量是first second 因为是使用struct不是class，
					所以可以直接使用pair的成员变量。
*/

#include <iostream>
#include <set>

using namespace std;

void test01()
{
	// set
	set<int> s;

	pair<set<int>::iterator, bool> ret = s.insert(10);

	if (ret.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}

	ret = s.insert(10);

	if (ret.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}



	// multiset
	multiset<int> ms;

	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << endl;

	}
	cout << endl;
}

int main()
{
	test01();

	return 0;
}