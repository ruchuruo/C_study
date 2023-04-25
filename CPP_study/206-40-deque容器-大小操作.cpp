
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

					功能描述：

						对deque容器的大小进行操作

					函数原型：

						deque.empty();           //判断容器是否为空

						deque.size();            //返回容器中元素的个数

						deque.resize(num);       //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
						                         //如果容器变短，则末尾超出容器长度的元素被删除。

						deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
						                         //如果容器变短，则末尾超出容器长度的元素被删除。

					总结：

						deque没有容量的概念
						判断是否为空 --- empty
						返回元素个数 --- size
						重新指定个数 --- resize
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

	//判断容器是否为空
	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1不为空" << endl;
	}

	//返回容器中元素的个数
	// deque 容器没有容量概念
	cout << "d1的大小 " << d1.size() << endl;

	//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
	d1.resize(15);
	printDeque(d1);

	//重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
	d1.resize(20, 666);
	printDeque(d1);

	//如果容器变短，则末尾超出容器长度的元素被删除。
	d1.resize(5);
	printDeque(d1);
}

int main()
{
	test01();

	return 0;
}