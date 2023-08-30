
/*
	第1阶段C++ 匠心之作 从0到1入门

	第2阶段实战-通讯录管理

	第3阶段-C++核心编程

	第4阶段实战-基于多态的企业职工系统

	第5阶段-C++提高编程

		1 模板

		2 STL初识

		3 STL- 常用容器

		4 STL- 函数对象

			4.1 函数对象

				4.1.1 函数对象概念

					概念：

						重载函数调用操作符的类，其对象常称为函数对象
						函数对象使用重载的()时，行为类似函数调用，也叫仿函数

					本质：

						函数对象(仿函数)是一个类，不是一个函数

				4.1.2 函数对象使用

					特点：

						函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
						函数对象超出普通函数的概念，函数对象可以有自己的状态
						函数对象可以作为参数传递

					总结：

						仿函数写法非常灵活，可以作为参数进行传递。
*/

#include <iostream>

using namespace std;

// 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

// 函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}

	void operator()(string t)
	{
		cout << t << endl;
		this->count++;
	}

	// 普通函数自己想统计自己调用了多少次，需要全局变量或是静态变量等，需要借助外力
	// 函数对象可以有自己的状态
	int count;// 内部自己的状态
};

// 函数对象可以作为参数传递
void pppPrint(MyPrint& p, string t)
{
	p(t);
}

void test01()
{
	// 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
	MyAdd add;
	cout << add(10, 11) << endl;

	// 函数对象超出普通函数的概念，函数对象可以有自己的状态
	MyPrint print;
	print("hello world");
	print("hello world");
	print("hello world");
	cout << print.count << endl;

	// 函数对象可以作为参数传递
	pppPrint(print, "hello");
}

int main()
{
	test01();

	return 0;
}