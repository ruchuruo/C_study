
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

					功能描述：

						对string字符串进行插入和删除字符操作

					函数原型：

						string& insert(int pos, const char* s);   //插入字符串
						string& insert(int pos, const string& str);  //插入字符串
						string& insert(int pos, int n, char c); //在指定位置插入n个字符c
						string& erase(int pos, int n = npos); //删除从Pos开始的n个字符

					总结：插入和删除的起始下标都是从0开始
*/

#include <iostream>

using namespace std;

//字符串插入和删除
void test01()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);  //从1号位置开始3个字符
	cout << str << endl;
}

int main()
{
	test01();

	return 0;
}