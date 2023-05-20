
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

					功能描述：

						创建list容器

					函数原型：

						list<T> lst;           //list采用采用模板类实现,对象的默认构造形式：
						list(beg,end);         //构造函数将[beg, end)区间中的元素拷贝给本身。
						list(n,elem);          //构造函数将n个elem拷贝给本身。
						list(const list &lst); //拷贝构造函数。

					总结：list构造方式同其他几个STL常用容器，熟练掌握即可
*/

#include <iostream>
#include <list>

using namespace std;

void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	// 对象的默认构造形式
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	// 遍历
	printList(l1);

	//构造函数将[beg, end)区间中的元素拷贝给本身。
	list<int> l2(l1.begin(), l1.end());
	printList(l2);

	//拷贝构造函数。
	list<int> l3(l2);
	printList(l3);

	//构造函数将n个elem拷贝给本身。
	list<int> l4(10, 666);
	printList(l4);
}

int main()
{
	test01();

	return 0;
}