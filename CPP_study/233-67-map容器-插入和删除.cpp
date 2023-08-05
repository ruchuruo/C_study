
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

					功能描述：

						map容器进行插入数据和删除数据

					函数原型：

						insert(elem);    //在容器中插入元素。
						clear();         //清除所有元素
						erase(pos);      //删除pos迭代器所指的元素，返回下一个元素的迭代器。
						erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
						erase(key);      //删除容器中值为key的元素。

					总结：

						map插入方式很多，记住其一即可
						插入 --- insert
						删除 --- erase
						清空 --- clear
*/

#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " = " << (*it).second << endl;
	}
	cout << endl;
}

//在容器中插入元素
void test01()
{
	map<int, int> m;

	//在容器中插入元素，方式1 匿名对组
	m.insert(pair<int, int>(1, 10));

	//在容器中插入元素，方式2 对组
	m.insert(make_pair(2, 10));

	//在容器中插入元素，方式3 值类型
	m.insert(map<int, int>::value_type(3, 10));



	//在容器中插入元素，方式4 重载[]
	// 不推荐，如果容器中已经有相同的key，会覆盖之前key的value
	m[3] = 11;

	// 但是[]可以用key访问到value，前提是确定有这个key，否则会自动创建
	cout << m[3] << endl;
	cout << m[5] << endl;

	printMap(m);
}

void test02()
{
	cout << endl;
	cout << endl;

	map<int, int> m;

	m.insert(make_pair(1, 11));
	m.insert(make_pair(2, 21));
	m.insert(make_pair(3, 31));
	m.insert(make_pair(4, 41));
	m.insert(make_pair(5, 51));
	m.insert(make_pair(6, 61));

	printMap(m);

	//删除pos迭代器所指的元素，返回下一个元素的迭代器。
	m.erase(m.begin());

	printMap(m);


	//删除容器中值为key的元素。
	m.erase(3);

	printMap(m);


	//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	m.erase(++m.begin(), --m.end());

	printMap(m);


	//清除所有元素
	m.clear();

	printMap(m);
}

int main()
{
	//在容器中插入元素。
	test01();

	// 删除元素
	test02();

	return 0;
}