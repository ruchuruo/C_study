
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

					功能描述：

						对list容器中数据进行存取

					函数原型：

						front(); //返回第一个元素。
						back();  //返回最后一个元素。

					总结：

						list容器中不可以通过[]或者at方式访问数据
						返回第一个元素   --- front
						返回最后一个元素 --- back
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
	list<int> l;

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);

	// list容器中不可以通过[]或者at方式访问数据
	//l[0];
	//l.at();

	cout << "第一个元素 " << l.front() << endl;
	cout << "最后一个元素 " << l.back() << endl;

	// 验证迭代器是否支持随机访问
	list<int>::iterator it = l.begin();
	it++;// 支持双向
	it--;// 支持双向
	//it + 1;// 不支持随机访问
}

int main()
{
	test01();

	return 0;
}