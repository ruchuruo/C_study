
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

				3.1.8 string插入和删除

				3.1.9 string子串

					功能描述：

						从字符串中获取想要的子串
						(从 字符串 中获取想要的 一小段字符串)

					函数原型：

						string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串

					总结：灵活的运用求子串功能，可以在实际开发中获取有效的信息
*/

#include <iostream>

using namespace std;

//子串
void test01()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;
}

// 实用操作
void test02()
{
	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;
}

int main()
{
	test01();

	// 实用操作
	test02();

	return 0;
}