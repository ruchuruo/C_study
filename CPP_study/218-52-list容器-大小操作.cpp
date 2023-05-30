
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

					功能描述：

						对list容器的大小进行操作

					函数原型：

						size();            //返回容器中元素的个数

						empty();           //判断容器是否为空

						resize(num);       //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
										   //如果容器变短，则末尾超出容器长度的元素被删除。

						resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
										   //如果容器变短，则末尾超出容器长度的元素被删除。

					总结：

						判断是否为空 --- empty
						返回元素个数 --- size
						重新指定个数 --- resize
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
	list<int> l1;

	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printList(l1);

	//判断容器是否为空
	if (l1.empty())
	{
		cout << "l1为空" << endl;
	}
	else
	{
		cout << "l1不为空" << endl;
	}

	//返回容器中元素的个数
	cout << "l1元素个数：" << l1.size() << endl;

	//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
	l1.resize(10);
	printList(l1);

	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
	l1.resize(15, 666);
	printList(l1);

	//如果容器变短，则末尾超出容器长度的元素被删除。
	l1.resize(3);
	printList(l1);
}

int main()
{
	test01();

	return 0;
}