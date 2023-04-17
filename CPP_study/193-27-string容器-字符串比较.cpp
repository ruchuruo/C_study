
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

					功能描述：

						字符串之间的比较

					比较方式：

						字符串比较是按字符的ASCII码进行对比

						= 返回 0

						> 返回 1

						< 返回 -1

					函数原型：

						int compare(const string &s) const; //与字符串s比较
						int compare(const char *s) const;   //与字符串s比较

					总结：字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大
*/

#include <iostream>

using namespace std;

//字符串比较
void test01()
{
	string s1 = "hello";
	string s2 = "aello";

	int ret = s1.compare(s2);

	if (ret == 0)
	{
		cout << "s1 等于 s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 大于 s2" << endl;
	}
	else
	{
		cout << "s1 小于 s2" << endl;
	}
}

int main()
{
	test01();

	return 0;
}