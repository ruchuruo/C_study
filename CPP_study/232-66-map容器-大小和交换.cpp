
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

					功能描述：

						统计map容器大小以及交换map容器

					函数原型：

						size();   //返回容器中元素的数目
						empty();  //判断容器是否为空
						swap(st); //交换两个集合容器

					总结：

						统计大小     --- size
						判断是否为空 --- empty
						交换容器     --- swap
*/

#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " = " << (*it).second << endl;
	}
	cout << endl;
}

// 大小
void test01()
{
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 10));
	m.insert(pair<int, int>(4, 10));

	//判断容器是否为空
	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << " 大小 ";

		//返回容器中元素的数目
		cout << m.size() << endl;
	}
}

// 交换
void test02()
{
	map<int, int> m1;
	map<int, int> m2;

	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 10));
	m1.insert(pair<int, int>(3, 10));

	m2.insert(pair<int, int>(10, 100));
	m2.insert(pair<int, int>(20, 100));
	m2.insert(pair<int, int>(30, 100));

	cout << "交换前" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "交换后" << endl;
	printMap(m1);
	printMap(m2);
}

int main()
{
	// 大小
	test01();

	// 交换
	test02();

	return 0;
}