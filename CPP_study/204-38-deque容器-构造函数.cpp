
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

					功能：

						双端数组，可以对头端进行插入删除操作

					deque与vector区别：

						vector对于头部的插入删除效率低，数据量越大，效率越低
						deque相对而言，对头部的插入删除速度回比vector快
						vector访问元素时的速度会比deque快,这和两者内部实现有关

						|   deque容器
						|   
						|                            insert()
						|   push_front()                |                push_back()
						|       ↓           front()     ↓      back()        ↓
						|        ↘       -----------------------------     ↙
						|           →→→                                 ←←←
						|                   [   ][   ][   ][   ][   ]
						|           ←←←                                 →→→
						|        ↙       -----------------------------     ↘
						|       ↓             ↑                   ↑          ↓
						|   pop_front()       |                   |      pop_back()
						|                   begin()              end()

					deque内部工作原理:

						deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据

						中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

						|    中控器
						|   +------+
						|   |      |
						|   |      |
						|   |      |
						|   |------|
						|   |      |
						|   |      |
						|   |      |
						|   |------|
						|   |      |   +--------------------------------+
						|   | 0x01 | → | [   ][   ][   ][ 4 ][ 5 ][ 6 ] |
						|   |      |   +--------------------------------+
						|   |------|
						|   |      |   +--------------------------------+
						|   | 0x02 | → | [ 7 ][ 8 ][ 9 ][1 0][1 1][1 2] |
						|   |      |   +--------------------------------+
						|   |------|
						|   |      |   +--------------------------------+
						|   | 0x03 | → | [1 3][1 4][1 5][   ][   ][   ] |
						|   |      |   +--------------------------------+
						|   |------|
						|   |      |
						|   |      |
						|   |      |
						|   |------|
						|   |      |
						|   |      |
						|   |      |
						|   +------+

						deque容器的迭代器也是支持随机访问的

				3.3.2 deque构造函数

					功能描述：

						deque容器构造

					函数原型：

						deque<T> deqT;           //默认构造形式
						deque(beg, end);         //构造函数将[beg, end)区间中的元素拷贝给本身。
						deque(n, elem);          //构造函数将n个elem拷贝给本身。
						deque(const deque &deq); //拷贝构造函数

					总结：deque容器和vector容器的构造方式几乎一致，灵活使用即可
*/

#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d)
{
	// 只读 迭代器
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	//默认构造形式
	deque<int> d1;

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//构造函数将[beg, end)区间中的元素拷贝给本身。
	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	//构造函数将n个elem拷贝给本身。
	deque<int> d3(10, 666);
	printDeque(d3);

	//拷贝构造函数
	deque<int> d4(d3);
	printDeque(d4);
}

int main()
{
	test01();

	return 0;
}