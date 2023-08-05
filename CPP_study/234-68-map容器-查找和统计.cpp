
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

			3.9 map/ multimap容器

				3.9.1 map基本概念

				3.9.2 map构造和赋值

				3.9.3 map大小和交换

				3.9.4 map插入和删除

				3.9.5 map查找和统计

					功能描述：

						对map容器进行查找数据以及统计数据

					函数原型：

						find(key);  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
						count(key); //统计key的元素个数

					总结：

						查找 --- find  （返回的是迭代器）
						统计 --- count （对于map，结果为0或者1）
*/

#include <iostream>
#include <map>

using namespace std;

void test01()
{
	map<int, int> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(3, 31));
	m.insert(make_pair(4, 40));

	//查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回map.end();
	map<int, int>::iterator pos = m.find(3);

	if (pos == m.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到 " << pos->first << " = " << pos->second << endl;
	}


	//统计key的元素个数
	cout << m.count(3) << endl;
}

int main()
{
	test01();

	return 0;
}