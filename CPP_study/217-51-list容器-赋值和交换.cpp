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

					功能描述：

						给list容器进行赋值，以及交换list容器

					函数原型：

						assign(beg, end);                 //将[beg, end)区间中的数据拷贝赋值给本身。
						assign(n, elem);                  //将n个elem拷贝赋值给本身。
						list& operator=(const list &lst); //重载等号操作符
						swap(lst);                        //将lst与本身的元素互换。

					总结：list赋值和交换操作能够灵活运用即可
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

// 赋值
void test01()
{
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printList(l1);


	
	list<int> l2;
	list<int> l3;
	list<int> l4;

	// 赋值 重载等号操作符
	l2 = l1;

	//将[beg, end)区间中的数据拷贝赋值给本身。
	l3.assign(l1.begin(), l1.end());

	//将n个elem拷贝赋值给本身。
	l4.assign(10, 666);

	printList(l2);
	printList(l3);
	printList(l4);
}

void test02()
{
	cout << endl;

	list<int> l1;
	list<int> l2;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	l2.assign(10, 999);

	cout << "交换前" << endl;
	printList(l1);
	printList(l2);

	cout << endl;

	//将lst与本身的元素互换。
	l1.swap(l2);

	cout << "交换后" << endl;
	printList(l1);
	printList(l2);
}

int main()
{
	// 赋值
	test01();

	// 交换
	test02();

	return 0;
}