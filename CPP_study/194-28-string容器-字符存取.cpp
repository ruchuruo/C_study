
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

				3.1.1 string基本概念

				3.1.2 string构造函数

				3.1.3 string赋值操作

				3.1.4 string字符串拼接

				3.1.5 string查找和替换

				3.1.6 string字符串比较

				3.1.7 string字符存取

					string中单个字符存取方式有两种

						char& operator[](int n); //通过[]方式取字符
						char& at(int n);         //通过at方法获取字符

					总结：string字符串中单个字符存取有两种方式，利用 [ ] 或 at
*/

#include <iostream>

using namespace std;

void test01()
{
	string str = "hello world";

	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
}

int main()
{
	test01();

	return 0;
}