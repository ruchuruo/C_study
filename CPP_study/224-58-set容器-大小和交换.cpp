
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

					功能描述：

						统计set容器大小以及交换set容器

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
#include <set>

using namespace std;

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 统计大小
// 判断是否为空
void test01()
{
	set<int> s;

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	printSet(s);

	// 判断是否为空
	if (s.empty())
	{
		cout << "空" << endl;
	}
	else
	{
		cout << "不空" << endl;

		// 统计大小
		cout << "大小 " << s.size() << endl;
	}
}

// 交换容器
void test02()
{
	cout << endl;

	set<int> s1;
	set<int> s2;

	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);

	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);

	// 交换容器
	s1.swap(s2);

	cout << "交换后" << endl;
	printSet(s1);
	printSet(s2);
}



int main()
{
	// 统计大小
	// 判断是否为空
	test01();

	// 交换容器
	test02();

	return 0;
}