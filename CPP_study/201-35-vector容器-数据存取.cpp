
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

				3.2.1 vector基本概念

				3.2.2 vector构造函数

				3.2.3 vector赋值操作

				3.2.4 vector容量和大小

				3.2.5 vector插入和删除

				3.2.6 vector数据存取

					功能描述：

						对vector中的数据的存取操作

					函数原型：

						at(int idx); //返回索引idx所指的数据
						operator[];  //返回索引idx所指的数据
						front();     //返回容器中第一个数据元素
						back();      //返回容器中最后一个数据元素

					总结：

						除了用迭代器获取vector容器中元素，[ ]和at也可以
						front返回容器第一个元素
						back返回容器最后一个元素
*/

#include <iostream>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	// at(int idx); //返回索引idx所指的数据
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	// operator[];  //返回索引idx所指的数据
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	// front();     //返回容器中第一个数据元素
	cout << v1.front() << endl;

	// back();      //返回容器中最后一个数据元素
	cout << v1.back() << endl;
}

int main()
{
	test01();

	return 0;
}