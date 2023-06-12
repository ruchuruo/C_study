
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

				3.7.4 list 大小操作

				3.7.5 list 插入和删除

				3.7.6 list 数据存取

				3.7.7 list 反转和排序

					功能描述：

						将容器中的元素反转，以及将容器中的数据进行排序

					函数原型：

						reverse(); //反转链表
						sort();    //链表排序

					总结：

						反转 --- reverse
						排序 --- sort （成员函数）
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

bool myCompare(int v1, int v2)
{
	// 降序 v1 > v2
	return v1 > v2;
}

void test01()
{
	list<int> l;

	l.push_back(20);
	l.push_back(10);
	l.push_back(50);
	l.push_back(40);
	l.push_back(30);

	printList(l);

	//反转链表
	l.reverse();

	printList(l);

	//链表排序
	// 不支持随机访问迭代器的容器 不能用标准算法
	//sort(l.begin(), l.end());
	// 不支持随机访问迭代器的容器 内部会提供对应的一些算法
	l.sort();// 默认从小到大 升序

	printList(l);

	//链表排序 从大到小 降序
	l.sort(myCompare);

	printList(l);
}

int main()
{
	test01();

	return 0;
}










/*
	底层代码
		《老师看了也会迷糊》
*/