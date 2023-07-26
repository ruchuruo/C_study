
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

			3.8 set/ multiset 容器

				3.8.1 set基本概念

				3.8.2 set构造和赋值

				3.8.3 set大小和交换

				3.8.4 set插入和删除

					功能描述：

						set容器进行插入数据和删除数据

					函数原型：

						insert(elem);    //在容器中插入元素。
						clear();         //清除所有元素
						erase(pos);      //删除pos迭代器所指的元素，返回下一个元素的迭代器。
						erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
						erase(elem);     //删除容器中值为elem的元素。

					总结：

						插入 --- insert
						删除 --- erase
						清空 --- clear
*/

#include <iostream>
#include <set>

using namespace std;

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int> s;

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	s.insert(60);

	printSet(s);

	//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	s.erase(++s.begin());

	printSet(s);

	//删除容器中值为elem的元素。
	s.erase(30);

	printSet(s);

	//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	s.erase(++s.begin(), --s.end());

	printSet(s);

	//清除所有元素
	s.clear();

	printSet(s);
}

int main()
{
	test01();

	return 0;
}