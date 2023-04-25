
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

				3.3.1 deque容器基本概念

				3.3.2 deque构造函数

				3.3.3 deque赋值操作

					功能描述：

						给deque容器进行赋值

					函数原型：

						deque& operator=(const deque &deq); //重载等号操作符

						assign(beg, end);                   //将[beg, end)区间中的数据拷贝赋值给本身。

						assign(n, elem);                    //将n个elem拷贝赋值给本身。

					总结：deque赋值操作也与vector相同，需熟练掌握
*/

#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//重载等号操作符
	deque<int> d2;
	d2 = d1;
	printDeque(d2);

	//将[beg, end)区间中的数据拷贝赋值给本身。
	deque<int> d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	//将n个elem拷贝赋值给本身。
	deque<int> d4;
	d4.assign(10, 666);
	printDeque(d4);
}

int main()
{
	test01();

	return 0;
}