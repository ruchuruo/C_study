
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

					简介：

						所有元素都会在插入时自动被排序
						(翻译过来也叫集合容器)

					本质：

						set/multiset属于关联式容器，底层结构是用二叉树实现。

					set和multiset区别：

						set不允许容器中有重复的元素
						multiset允许容器中有重复的元素

				3.8.2 set构造和赋值

					功能描述：创建set容器以及赋值

					构造：

						set<T> st;          //默认构造函数：
						set(const set &st); //拷贝构造函数

					赋值：

						set& operator=(const set &st); //重载等号操作符

					总结：

						set容器插入数据时用insert
						set容器插入数据的数据会自动排序
						set容器不允许容器中有重复的元素
*/

#include <iostream>
#include <set>

using namespace std;

void printSet(set<int> &s)
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

	// 插入数据只有 insert 方式
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(30);

	// 遍历容器
	printSet(s);


	// 拷贝构造
	set<int> s2(s);

	printSet(s);


	// 赋值
	set<int> s3;
	s3 = s2;

	printSet(s);
}


int main()
{
	test01();

	return 0;
}