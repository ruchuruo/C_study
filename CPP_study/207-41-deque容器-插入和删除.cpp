
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

					功能描述：

						向deque容器中插入和删除数据

					函数原型：

						两端插入删除操作：

							push_back(elem);  //在容器尾部添加一个数据
							push_front(elem); //在容器头部插入一个数据
							pop_back();       //删除容器最后一个数据
							pop_front();      //删除容器第一个数据

						指定位置操作：

							insert(pos,elem);    //在pos位置插入一个elem元素的拷贝，返回新数据的位置。

							insert(pos,n,elem);  //在pos位置插入n个elem数据，无返回值。

							insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。

							clear();             //清空容器的所有数据

							erase(beg,end);      //删除[beg,end)区间的数据，返回下一个数据的位置。

							erase(pos);          //删除pos位置的数据，返回下一个数据的位置。

						总结：

							插入和删除提供的位置是迭代器！
							尾插 --- push_back
							尾删 --- pop_back
							头插 --- push_front
							头删 --- pop_front
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

// 两端插入操作
void test01()
{
	deque<int> d1;

	// 尾插
	d1.push_back(10);
	d1.push_back(20);

	// 头插
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1);

	// 尾删
	d1.pop_back();
	printDeque(d1);

	// 头删
	d1.pop_front();
	printDeque(d1);

	cout << endl;
}

// 指定位置操作
void test02()
{
	deque<int> d1;
	deque<int> d2;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	printDeque(d1);



	//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
	d1.insert(d1.begin() + 2, 666);

	printDeque(d1);

	//在pos位置插入n个elem数据，无返回值。
	d1.insert(d1.begin() + 3, 2, 999);
	printDeque(d1);

	//在pos位置插入[beg,end)区间的数据，无返回值。
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1);

	cout << endl;
}

// 指定位置删除操作
void test03()
{
	deque<int> d1;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1);

	//删除pos位置的数据，返回下一个数据的位置。
	d1.erase(d1.begin());
	printDeque(d1);

	//删除[beg,end)区间的数据，返回下一个数据的位置。
	d1.erase(d1.begin() + 1, d1.begin() + 3);
	printDeque(d1);

	//清空容器的所有数据
	d1.clear();
	printDeque(d1);
}

int main()
{
	// 两端插入删除操作
	test01();

	// 指定位置插入操作
	test02();

	// 指定位置删除操作
	test03();

	return 0;
}