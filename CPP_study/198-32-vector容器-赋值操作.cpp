
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

				3.2.1 vector基本概念

				3.2.2 vector构造函数

				3.2.3 vector赋值操作

					功能描述：

						给vector容器进行赋值

					函数原型：

						vector& operator=(const vector &vec); //重载等号操作符
						assign(beg, end);                     //将[beg, end)区间中的数据拷贝赋值给本身。
						assign(n, elem);                      //将n个elem拷贝赋值给本身。

					总结： vector赋值方式比较简单，使用operator=，或者assign都可以
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//赋值操作
void test01()
{
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	v2 = v1;
	printVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	vector<int>v4;
	v4.assign(10, 100);
	printVector(v4);
}

int main()
{
	test01();

	return 0;
}