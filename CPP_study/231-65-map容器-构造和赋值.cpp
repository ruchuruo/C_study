
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

					简介：

						map中所有元素都是pair
						pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
						所有元素都会根据元素的键值自动排序

					本质：

						map/multimap属于关联式容器，底层结构是用二叉树实现。

					优点：

						可以根据key值快速找到value值

					map和multimap区别：

						map不允许容器中有重复key值元素
						multimap允许容器中有重复key值元素

				3.9.2 map构造和赋值

					功能描述：

						对map容器进行构造和赋值操作

					函数原型：

						构造：
							map<T1, T2> mp;                //map默认构造函数
							map(const map &mp);            //拷贝构造函数

						赋值：
							map& operator=(const map &mp); //重载等号操作符

					总结：
						map中所有元素都是成对出现，插入数据时候要使用对组
*/

#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int> &m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " = " << (*it).second << endl;
	}
	cout << endl;
}

void test01()
{
	//map默认构造函数
	map<int, int> m;

	// 匿名对组
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));

	printMap(m);


	//拷贝构造函数
	map<int, int> m2(m);

	printMap(m2);


	//重载等号操作符
	map<int, int> m3;
	m3 = m2;

	printMap(m2);
}

int main()
{
	test01();

	return 0;
}