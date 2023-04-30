
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

				3.3.4 deque大小操作

				3.3.5 deque 插入和删除

				3.3.6 deque 数据存取

					功能描述：

						对deque 中的数据的存取操作

					函数原型：

						at(int idx); //返回索引idx所指的数据
						operator[];  //返回索引idx所指的数据
						front();     //返回容器中第一个数据元素
						back();      //返回容器中最后一个数据元素

					总结：

						除了用迭代器获取deque容器中元素，[ ]和at也可以
						front返回容器第一个元素
						back返回容器最后一个元素
*/

#include <iostream>
#include <deque>

using namespace std;

void test01()
{
	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	// at(int idx); //返回索引idx所指的数据
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	// operator[];  //返回索引idx所指的数据
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	// front();     //返回容器中第一个数据元素
	cout << "第一个元素 " << d.front() << endl;

	// back();      //返回容器中最后一个数据元素
	cout << "最后一个元素 " << d.back() << endl;
}

int main()
{
	test01();

	return 0;
}