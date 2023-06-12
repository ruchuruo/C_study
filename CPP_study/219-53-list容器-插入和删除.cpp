
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

					功能描述：

						对list容器进行数据的插入和删除

					函数原型：

						push_back(elem);     //在容器尾部加入一个元素
						pop_back();          //删除容器中最后一个元素
						push_front(elem);    //在容器开头插入一个元素
						pop_front();         //从容器开头移除第一个元素
						insert(pos,elem);    //在pos位置插elem元素的拷贝，返回新数据的位置。
						insert(pos,n,elem);  //在pos位置插入n个elem数据，无返回值。
						insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。
						clear();             //移除容器的所有数据
						erase(beg,end);      //删除[beg,end)区间的数据，返回下一个数据的位置。
						erase(pos);          //删除pos位置的数据，返回下一个数据的位置。
						remove(elem);        //删除容器中所有与elem值匹配的元素。

					总结：

						尾插 --- push_back
						尾删 --- pop_back
						头插 --- push_front
						头删 --- pop_front
						插入 --- insert
						删除 --- erase
						移除 --- remove
						清空 --- clear
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

	//在容器尾部加入一个元素
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	//在容器开头插入一个元素
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);

	printList(l);

	//删除容器中最后一个元素
	l.pop_back();

	printList(l);

	//从容器开头移除第一个元素
	l.pop_front();

	printList(l);

	//在pos位置插elem元素的拷贝，返回新数据的位置。
	l.insert(++l.begin(), 666);

	printList(l);

	//删除pos位置的数据，返回下一个数据的位置。
	l.erase(++l.begin());

	printList(l);


	//删除容器中所有与elem值匹配的元素。
	l.push_back(99999);
	l.push_back(99999);
	l.push_back(99999);

	printList(l);

	l.remove(99999);

	printList(l);

	//移除容器的所有数据
	l.clear();

	printList(l);
}

int main()
{
	test01();

	return 0;
}