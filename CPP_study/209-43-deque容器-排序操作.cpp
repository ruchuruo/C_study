
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

				3.3.7 deque 排序

					功能描述：

						利用算法实现对deque容器进行排序

					算法：

						sort(iterator beg, iterator end) //对beg和end区间内元素进行排序

					总结：
						sort算法非常实用，使用时包含头文件 algorithm即可

						对于支持随机访问的迭代器的容器，都可以利用sort算法直接进行排序
*/

#include <iostream>
#include <deque>
#include <algorithm>

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
	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	printDeque(d);

	// sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
	// 默认 从小到大 升序
	sort(d.begin(), d.end());

	printDeque(d);
}

int main()
{
	test01();

	return 0;
}