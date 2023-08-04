
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

				3.8.5 set查找和统计

				3.8.6 set和multiset区别

				3.8.7 pair对组创建

					功能描述：

						成对出现的数据，利用对组可以返回两个数据

					两种创建方式：

						pair<type, type> p ( value1, value2 );
						pair<type, type> p = make_pair( value1, value2 );

					总结：

						两种方式都可以创建对组，记住一种即可
*/

#include <iostream>

using namespace std;

void test01()
{
	// pair<type, type> p ( value1, value2 );
	pair<string, int> p("Tom", 20);

	cout << p.first << " " << p.second << endl;


	// pair<type, type> p = make_pair( value1, value2 );
	pair<string, int> p2 = make_pair("张三", 30);
	cout << p2.first << " " << p2.second << endl;
}

int main()
{
	test01();

	return 0;
}