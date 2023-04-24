
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

				3.2.7 vector互换容器

				3.2.8 vector预留空间

					功能描述：

						减少vector在动态扩展容量时的扩展次数

					函数原型：

						reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

					总结：如果数据量较大，可以一开始利用reserve预留空间
*/

#include <iostream>
#include <vector>

using namespace std;

void test01()
{
	vector<int> v;

	// 统计动态扩展次数
	int num = 0;
	int* p = NULL;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		// 通过 容量 对比 大小 来统计扩展次数
		//if (v.size() == v.capacity())
		//{
		//	num++;
		//}


		// 通过存放内容的 首地址 来统计扩展次数
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "v的容量 " << v.capacity() << endl;
	cout << "v的大小 " << v.size() << endl;
	cout << "扩展了" << num << endl;
}

// 利用 reserve() 预留空间
void test02()
{
	vector<int> v;

	v.reserve(100000);

	// 统计动态扩展次数
	int num = 0;
	int* p = NULL;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		// 通过 容量 对比 大小 来统计扩展次数
		//if (v.size() == v.capacity())
		//{
		//	num++;
		//}


		// 通过存放内容的 首地址 来统计扩展次数
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "v的容量 " << v.capacity() << endl;
	cout << "v的大小 " << v.size() << endl;
	cout << "扩展了" << num << endl;
}

int main()
{
	test01();

	// 利用 reserve() 预留空间
	test02();

	return 0;
}